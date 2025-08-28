#include<bits/stdc++.h>
#define taskname "2059C"
using namespace std;
const int INF = 1e9;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n;
		cin >> n;
		vector<vector<int>>a(n, vector<int>(n));
		vector<int>cnt(n + 1, 0);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> a[i][j];
			}
			int N = 0;
			while(!a[i].empty() && a[i].back() == 1){
				cnt[N++]++;
				a[i].pop_back();
			}
			cnt[N]++;
		}
		int ans = n;
		cnt[0]--;
		for(int i = 1; i < n; i++){
			if(cnt[i] > cnt[i - 1]){
				cnt[i] = cnt[i - 1];
			}
			if(cnt[i]-- == 0){
				ans = i;
				break;
			}
		}
		cout << ans << "\n";
	}
}