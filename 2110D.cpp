#include<bits/stdc++.h>
#define taskname "2110D"
using namespace std;
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
int n, m;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		cin >> n >> m;
		vector<vector<pair<int, int>>>g(n + 1);
		vector<int>b(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> b[i];
		}
		for(int i = 0; i < m; i++){
			int s, t, w;
			cin >> s >> t >> w;
			g[s].emplace_back(t, w);
		}
		int low = 1, high = 1e9, ans = -1;
		while(low <= high){
			int mid = (low + high) >> 1;
			vector<int>dp(n + 1, -1);
			dp[1] = min(b[1], mid);
			for(int i = 1; i <= n; i++){
				for(auto& [j, w] : g[i]){
					if(w <= dp[i]){
						maximize(dp[j], min(dp[i] + b[j], mid));
					}
				}
			} 
			if(dp[n] == -1){
				low = mid + 1;
			}
			else{
				high = (ans = mid) - 1;
			}
		}
		cout << ans << "\n";
	}
}