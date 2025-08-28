#include<bits/stdc++.h>
#define taskname "2028E"
using namespace std;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
const int lim = 2e5 + 5;
const int mod = 998244353;
const int INF = 1e9;
int power(int a, int b){
	int ans = 1;
	for(; b > 0; b >>= 1, a = 1LL * a * a % mod){
		if(b & 1){
			ans = 1LL * ans * a % mod;
		}
	}
	return ans;
}
vector<int>g[lim];
int dp[lim], h[lim], min_h[lim];
void dfs_1(int s, int p = -1){
	if(g[s].size() == 1 && g[s][0] == p){
		dp[s] = 0;
		min_h[s] = h[s];
		return;
	}
	int v = -1;
	min_h[s] = INF;
	for(int& d : g[s]){
		if(d != p){
			h[d] = h[s] + 1;
			dfs_1(d, s);
			minimize(min_h[s], min_h[d]);
			if(v == -1 || min_h[d] < min_h[v]){
				v = d;
			} 
		}
	}
	dp[s] = power((2 - dp[v] + mod) % mod, mod - 2);
}
void dfs_2(int s, int p = -1){
	for(int& d : g[s]){
		if(d != p){
			dp[d] = 1LL * dp[s] * dp[d] % mod;
			dfs_2(d, s);
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
	for(int _ = h[1] = 0; _ < _t; _++){
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++){
			g[i].clear();
		}
		for(int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		dfs_1(1);
		dfs_2(dp[1] = 1);
		for(int i = 1; i <= n; i++){
			cout << dp[i] << " ";
		}
		cout << "\n";
	}
}