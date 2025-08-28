#include<bits/stdc++.h>
#define taskname "2059B"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, k;
		cin >> n >> k;
		vector<vector<int>>pos((k >> 1) + 1);
		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;
			if(x <= (k >> 1)){
				pos[x].emplace_back(i);
			}
		}
		int ans = (k >> 1) + 1;
		for(int i = 2; i <= k; i += 2){
			int cnt = upper_bound(pos[i >> 1].begin(), pos[i >> 1].end(), n - k + i) - lower_bound(pos[i >> 1].begin(), pos[i >> 1].end(), i);
			if(cnt < n - k + 1){
				ans = i >> 1;
				break;
			}
			else if(cnt > 1){
				ans = (i >> 1) + 1;
				break;
			}
		}
		cout << ans << "\n";
	}
}