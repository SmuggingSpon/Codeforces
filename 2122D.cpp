#include<bits/stdc++.h>
#define taskname "2122D"
using namespace std;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
const int INF = 1e9;
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
		vector<int>dp(n + 1, INF), ndp(n + 1);
		dp[1] = 0;
		for(int i = 0; true; i++){
			fill(ndp.begin(), ndp.end(), INF);
			for(int j = 1; j <= n; j++){
				minimize(ndp[j], dp[j] + 1);
				minimize(ndp[g[j][i % g[j].size()]], dp[j]);
			}
			if(ndp[n] != INF){
				cout << i + 1 << " " << ndp[n] << "\n";
				break; 
			}
			swap(dp, ndp);
		}
	}
}