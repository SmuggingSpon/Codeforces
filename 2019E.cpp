#include<bits/stdc++.h>
#define taskname "2019E"
using namespace std;
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
		vector<int>h(n + 1), max_h(n + 1), f(n + 2, h[1] = 0);
		function<void(int, int)>dfs;
		dfs = [&] (int s, int par){
			max_h[s] = h[s];
			for(int& d : g[s]){
				if(d != par){
					h[d] = h[s] + 1;
					dfs(d, s);
					maximize(max_h[s], max_h[d]);
				}
			}
			f[1]++;
			f[h[s]]--;
			f[max_h[s] + 1]++;
		};
		dfs(1, -1);
		int ans = n - 1;
		for(int i = 1; i <= n; i++){
			minimize(ans, f[i] += f[i - 1]);
		}
		cout << ans << "\n";
	}
}