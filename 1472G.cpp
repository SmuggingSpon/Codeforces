#include<bits/stdc++.h>
#define taskname "1472G"
using namespace std;
template<class T>void minimize(T& a, T b){
	if(a > b){
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
		int n, m;
		cin >> n >> m;
		vector<vector<int>>g(n + 1);
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			g[u].emplace_back(v);
		}
		vector<int>d(n + 1, -1);
		queue<int>q;
		q.push(1);
		d[1] = 0;
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int& v : g[u]){
				if(d[v] == -1){
					d[v] = d[u] + 1;
					q.push(v);
				}
			}
		}
		vector<int>p(n);
		iota(p.begin(), p.end(), 1);
		sort(p.begin(), p.end(), [&] (int i, int j) -> bool{
			return d[i] > d[j];
		});
		vector<int>dp(n + 1);
		for(int& u : p){
			dp[u] = d[u];
			for(int& v : g[u]){
				if(d[v] > d[u]){
					minimize(dp[u], dp[v]);
				}
				else{
					minimize(dp[u], d[v]);
				}
			}
		}
		for(int i = 1; i <= n; i++){
			cout << dp[i] << " ";
		}
		cout << "\n";
	}
}