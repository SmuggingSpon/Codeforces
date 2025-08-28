#include<bits/stdc++.h>
#define taskname "2107D"
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
		for(int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		vector<bool>out(n + 1, false), vis(n + 1);
		vector<int>parent(n + 1), h(n + 1);
		function<void(int, int&)>dfs;
		dfs = [&] (int s, int& vertex){
			vis[s] = true;
			if(h[s] > h[vertex] || (h[s] == h[vertex] && s > vertex)){
				vertex = s;
			}
			for(int& d : g[s]){
				if(!out[d] && d != parent[s]){
					h[d] = h[parent[d] = s] + 1;
					dfs(d, vertex);
				}
			}
		};
		vector<vector<int>>ans;
		for(int cnt = n; cnt > 0; ){
			fill(vis.begin(), vis.end(), false);
			for(int i = 1; i <= n; i++){
				if(!out[i] && !vis[i]){
					int a = i, b;
					h[i] = parent[i] = 0;
					dfs(i, a);
					h[b = a] = parent[a] = 0;
					dfs(a, b);
					cnt -= h[b] + 1;
					ans.emplace_back(vector<int>{h[b] + 1, max(a, b), min(a, b)});
					while(b != a){
						out[b] = true;
						b = parent[b];
					}
					out[a] = true;
				}
			}
		}
		sort(ans.begin(), ans.end(), greater<vector<int>>());
		for(vector<int>& ve : ans){
			cout << ve[0] << " " << ve[1] << " " << ve[2] << " ";
		}
		cout << "\n";
	}
}