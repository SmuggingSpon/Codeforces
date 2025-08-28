#include<bits/stdc++.h>
#define taskname "1991E"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>g(n + 1);
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		vector<int>color(n + 1, -1);
		function<bool(int)>dfs;
		dfs = [&] (int s){
			for(int& d : g[s]){
				if(color[d] == -1){
					color[d] = color[s] ^ 1;
					if(!dfs(d)){
						return false;
					}
				}
				else if(color[d] == color[s]){
					return false;
				}
			}
			return true;
		};
		bool play_as_alice = false;
		for(int i = 1; i <= n; i++){
			if(color[i] == -1){
				color[i] = 0;
				if(!dfs(i)){
					play_as_alice = true;
					break;
				}
			}
		}
		if(play_as_alice){
			cout << "Alice" << endl;
			for(int i = 0; i < n; i++){
				cout << "1 2" << endl;
				int a, b;
				cin >> a >> b;
			}
		}
		else{
			cout << "Bob" << endl;
			vector<vector<int>>p(2);
			for(int i = 1; i <= n; i++){
				p[color[i]].emplace_back(i);
			}
			for(int i = 0; i < n; i++){
				int a, b;
				cin >> a >> b;
				if(--a > --b){
					swap(a, b);
				}
				if(!p[a].empty()){
					cout << p[a].back() << " " << a + 1 << endl;
					p[a].pop_back();
				}
				else if(b == 1){
					cout << p[1].back() << " 2" << endl;
					p[1].pop_back();
				}
				else{
					cout << p[a ^= 1].back() << " 3" << endl;
					p[a].pop_back();
				}
			}
		}
	}
}
