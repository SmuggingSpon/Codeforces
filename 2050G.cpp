#include<bits/stdc++.h>
#define taskname "2050G"
using namespace std;
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
const int lim = 2e5 + 5;
int n, ans, dp[lim];
vector<int>g[lim];
void dfs_1(int s, int p = -1){
	int cnt = dp[s] = 0;
	for(int& d : g[s]){
		if(d != p){
			dfs_1(d, s);
			cnt++;
		}
	}
	for(int& d : g[s]){
		if(d != p){
			maximize(dp[s], dp[d]);
		}
	}
	dp[s] += cnt - 1;
	maximize(dp[s], cnt);
}
void dfs_2(int s, int p = -1){
	maximize(ans, dp[s] + int(p != -1));
	int cnt = 0;
	vector<int>value;
	for(int& d : g[s]){
		if(d != p){
			cnt++;
			value.emplace_back(dp[d]);
			dfs_2(d, s);
		}
	}
	if(cnt > 1){
		sort(value.begin(), value.end(), greater<int>());
		maximize(ans, value[0] + value[1] + cnt - 2 + int(p != -1));
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
		cin >> n;
		for(int i = ans = 1; i <= n; i++){
			g[i].clear();
		}
		for(int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		dfs_1(1);
		dfs_2(1);
		cout << ans << "\n";
	}
}