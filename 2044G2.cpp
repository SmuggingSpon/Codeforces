#include<bits/stdc++.h>
#define taskname "2044G2"
using namespace std;
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, ans = 0;
		cin >> n;
		vector<vector<int>>g(n + 1);
		vector<int>to(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> to[i];
			g[to[i]].emplace_back(i);
		}
		vector<bool>on_cycle(n + 1, false);
		vector<int>dp(n + 1, -1);
		function<int(int)>dfs;
		dfs = [&] (int s){
			if(dp[s] != -1){
				return dp[s];
			}
			dp[s] = 0;
			for(int& d : g[s]){
				if(on_cycle[d]){
					continue;
				}
				if(on_cycle[s]){
					maximize(dp[s], dfs(d) + 1);
				}
				else{
					dp[s] += dfs(d) + 1;
				}
			}
			return dp[s];
		};
		vector<int>id(n + 1, -1);
		for(int i = 1, ID = 0; i <= n; i++){
			if(id[i] == -1){
				int x = i;
				while(id[x] == -1){
					id[x] = ID;
					x = to[x];
				}
				if(id[x] != ID++){
					continue;
				}
				int y = x, cnt = 0;
				on_cycle[x] = true;
				while((y = to[y]) != x){
					on_cycle[y] = true;
				}
			}
			maximize(ans, dfs(i));
		}
		cout << ans + 2 << "\n";
	}
}