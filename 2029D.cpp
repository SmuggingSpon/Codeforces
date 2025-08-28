#include<bits/stdc++.h>
#define taskname "2029D"
using namespace std;
const int lim = 1e5 + 5;
int n, m;
set<int>g[lim];
vector<tuple<int, int, int>>ans;
void manipulate(int a, int b){
	if(g[a].find(b) != g[a].end()){
		g[a].erase(b);
		g[b].erase(a);
	}
	else{
		g[a].insert(b);
		g[b].insert(a);
	}
}
void work(int a, int b, int c){
	ans.emplace_back(a, b, c);
	manipulate(a, b);
	manipulate(a, c);
	manipulate(b, c);

}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		cin >> n >> m;
		for(int i = 1; i <= n; i++){
			g[i].clear();
		}
		ans.clear();
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			g[u].insert(v);
			g[v].insert(u);
		}
		for(int i = 1; i <= n; i++){
			while(g[i].size() > 1){
				int u = *g[i].begin(), v = *next(g[i].begin());
				work(i, u, v);
			}
		}
		vector<pair<int, int>>vertex;
		pair<int, int>root = make_pair(-1, -1);
		for(int i = 1; i <= n; i++){
			if(g[i].empty()){
				vertex.emplace_back(i, -1);
			}
			else if(i < *g[i].begin()){
				vertex.emplace_back(root = make_pair(i, *g[i].begin()));
			}
		}
		if(root.first != -1){
			vertex.erase(find(vertex.begin(), vertex.end(), root));
			for(auto& [u, v] : vertex){
				if(v == -1){
					ans.emplace_back(root.first, root.second, u);
					root.second = u;
				}
				else{
					ans.emplace_back(u, v, root.first);
				}
			}			
		}
		cout << ans.size() << "\n";
		for(auto& [a, b, c] : ans){
			cout << a << " " << b << " " << c << "\n";
		}
	}
}