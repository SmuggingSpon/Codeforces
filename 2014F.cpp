#include<bits/stdc++.h>
#define taskname "2014F"
using namespace std;
typedef long long ll;
const int lim = 2e5 + 5;
ll dp[lim][2];
int n, c, a[lim];
vector<int>g[lim];
void dfs(int s, int p = -1){
	dp[s][0] = 0;
	dp[s][1] = a[s];
	for(int& d : g[s]){
		if(d != p){
			dfs(d, s);
			dp[s][0] += max(dp[d][0], dp[d][1]);
			dp[s][1] += max(dp[d][0], dp[d][1] - (c << 1));
		}
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
		cin >> n >> c;
		for(int i = 1; i <= n; i++){ 
			cin >> a[i];
			g[i].clear();
		}
		for(int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		} 
		dfs(1);
		cout << max(dp[1][0], dp[1][1]) << "\n";
	}
}