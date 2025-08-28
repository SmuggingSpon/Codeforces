#include<bits/stdc++.h>
#define taskname "1905B"
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
		vector<vector<int>>e(n + 1);
		for(int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			e[u].emplace_back(v);
			e[v].emplace_back(u);
		}
		queue<int>q;
		q.push(1);
		int ans = 0;
		vector<bool>vis(n + 1, false);
		vis[1] = true;
		while(!q.empty()){
			int u = q.front();
			q.pop();
			bool leaf = true;
			for(int& v : e[u]){
				if(vis[v]){
					continue;
				}
				leaf = false;
				q.push(v);
				vis[v] = true;
			}
			if(leaf){
				ans++;
			}
		}
		if(e[1].size() == 1){
			ans++;
		}
		cout << (ans >> 1) + (ans & 1) << "\n"; 
	}
}
