#include<bits/stdc++.h>
#define taskname "2063C"
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
		int n;
		cin >> n;
		vector<vector<int>>g(n + 1);
		vector<int>deg(n + 1, 0);
		for(int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			g[u].emplace_back(v);
			g[v].emplace_back(u);
			deg[u]++;
			deg[v]++;
		}
		vector<bool>vis(n + 1, false);
		int ans = 0;
		vector<int>p(n);
		iota(p.begin(), p.end(), 1);
		sort(p.begin(), p.end(), [&] (int i, int j) -> bool{
			return deg[i] > deg[j];
		});
		for(int u = 1; u <= n; u++){
			for(int& v : g[u]){
				maximize(ans, deg[u] + deg[v] - 2);
				vis[v] = true;
			}
			for(int& v : p){
				if(u != v && !vis[v]){
					maximize(ans, deg[u] + deg[v] - 1);
					break;
				}
			}
			for(int& v : g[u]){
				vis[v] = false;
			}
		}
		cout << ans << "\n";
	}
}