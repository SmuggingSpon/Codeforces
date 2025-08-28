#include<bits/stdc++.h>
#define taskname "1986F"
using namespace std;
typedef long long ll;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
const int lim = 1e5 + 5;
int n, m, t_dfs = 0, cnt[lim], num[lim], low[lim];
ll ans = 0;
vector<int>g[lim];
void dfs(int s, int p = -1){
	low[s] = num[s] = ++t_dfs;
	cnt[s] = 1;
	for(int& d : g[s]){
		if(d != p){
			if(num[d] == 0){
				dfs(d, s);
				cnt[s] += cnt[d];
				minimize(low[s], low[d]);
				if(low[d] > num[s]){
					maximize(ans, 1LL * cnt[d] * (n - cnt[d]));
				}
			}
			else{
				minimize(low[s], num[d]);
			}
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
		for(int i = 1; i <= n; i++){
			g[i].clear();
		}
		cin >> n >> m;
		for(int _ = t_dfs = ans = 0; _ < m; _++){
			int u, v;
			cin >> u >> v;
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		fill(num + 1, num + n + 1, 0);
		dfs(1);
		cout << ((1LL * n * (n - 1)) >> 1LL) - ans << "\n";
	}
}
