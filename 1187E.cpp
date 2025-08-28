#include<bits/stdc++.h>
#define taskname "1187E"
using namespace std;
typedef long long ll;
template<class T>void maximize(T& a,  T b){
	if(a < b){
		a = b;
	}
}
const int lim = 2e5 + 5;
ll ans = 0, dp[lim];
int n, cnt[lim];
vector<int>g[lim];
void dfs_1(int s, int p = -1){
	dp[s] = 0;
	cnt[s] = 1;
	for(int& d : g[s]){
		if(d != p){
			dfs_1(d, s);
			cnt[s] += cnt[d];
			dp[s] += dp[d];
		}
	}
	dp[s] += cnt[s];
}
void dfs_2(int s, int p = -1){
	maximize(ans, dp[s]);
	for(int& d : g[s]){
		if(d != p){
			dp[s] -= dp[d] + cnt[d];
			cnt[s] -= cnt[d];
			dp[d] += dp[s] + cnt[s];
			int temp = cnt[d];
			cnt[d] = n;
			dfs_2(d, s);
			cnt[d] = temp;
			dp[d] -= dp[s] + cnt[s];
			cnt[s] += cnt[d];
			dp[s] += dp[d] + cnt[d];
		}
	}	
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n;
	for(int _ = 1; _ < n; _++){
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs_1(1);
	dfs_2(1);
	cout << ans;
}