#include<bits/stdc++.h>
#define taskname "2053E"
using namespace std;
typedef long long ll;
const int lim = 2e5 + 5;
vector<int>g[lim];
int n, leaf, parent[lim], P[lim];
void dfs(int s){
	for(int& d : g[s]){
		if(d != parent[s]){
			parent[d] = s;
			dfs(d);
			P[s] += P[d];
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
	for(int _ = parent[1] = 0; _ < _t; _++){
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
		leaf = 0;
		vector<pair<int, int>>candidate;
		for(int i = 1; i <= n; i++){
			if(g[i].size() == (P[i] = 1)){
				leaf++;
				P[i] = 0;
				continue;
			}
			for(int& j : g[i]){
				if(g[j].size() == 1){
					P[i] = 0;
					break;
				}
			}
		}
		dfs(1);
		ll ans = 1LL * leaf * (n - leaf);
		for(int i = 1; i <= n; i++){
			if(g[i].size() > 1){
				bool Q = false;
				for(int& j : g[i]){
					if(g[j].size() == 1){
						Q = true;
						break;
					}
				}
				if(Q){
					for(int& j : g[i]){
						if(g[j].size() > 1){
							ans += (j == parent[i] ? P[i] : P[1] - P[j]);
						}
					}
				}
			}			
		}
		cout << ans << "\n";
	}
}