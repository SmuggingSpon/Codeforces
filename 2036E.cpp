#include<bits/stdc++.h>
#define taskname "2036E"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int n, k, q;
	cin >> n >> k >> q;
	vector<vector<int>>a(n + 1, vector<int>(k + 1));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= k; j++){
			a[i][j] |= a[i - 1][j];
		}
	}
	for(int _ = 0; _ < q; _++){
		int m;
		cin >> m;
		pair<int, int>ans = make_pair(1, n);
		for(int _m = 0; _m < m; _m++){
			int r, c;
			char o;
			cin >> r >> o >> c;
			if(ans.first != -1){
				int low = ans.first, high = ans.second, p = -1;
				if(o == '<'){
					while(low <= high){
						int mid = (low + high) >> 1;
						if(a[mid][r] < c){
							low = (p = mid) + 1;
						}
						else{
							high = mid - 1;
						}
					}
					if(p == -1){
						ans.first = -1;
					}
					ans.second = p;
				}
				else{
					while(low <= high){
						int mid = (low + high) >> 1;
						if(a[mid][r] > c){
							high = (p = mid) - 1;
						}
						else{
							low = mid + 1;
						}
					}
					if(p == -1){
						ans.first = -1;
					}
					ans.first = p;
				}
			}
		}
		cout << ans.first << "\n";
	}
}