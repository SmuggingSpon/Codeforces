#include<bits/stdc++.h>
#define taskname "2065F"
using namespace std;
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
		vector<int>a(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		vector<bool>ans(n + 1, false);
		vector<int>parent(n + 1);
		parent[1] = -1;
		auto dfs = [&] (auto&& self, int s) -> void{
			map<int, bool>cnt;
			for(int& d : g[s]){
				if(d != parent[s]){
					if(cnt[a[d]]){
						ans[a[d]] = true;
					}
					else{
						cnt[a[d]] = true;
					}
					parent[d] = s;
					self(self, d);
				}
			}	
		};
		dfs(dfs, 1);
		for(int i = 2; i <= n; i++){
			if(a[i] == a[parent[i]] || (parent[i] != 1 && a[i] == a[parent[parent[i]]])){
				ans[a[i]] = true;
			}
		}
		for(int i = 1; i <= n; i++){
			cout << ans[i];
		}
		cout << "\n";
	}
}