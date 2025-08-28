#include<bits/stdc++.h>
#define taskname "1998D"
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
		int n, m;
		cin >> n >> m;
		vector<vector<int>>g(n + 1);
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			g[u].emplace_back(v);
		}
		vector<int>dp(n + 1, n);
		dp[1] = 0;
		for(int i = 1; i < n; i++){
			minimize(dp[i + 1], dp[i] + 1);
			for(int& j : g[i]){
				minimize(dp[j], dp[i] + 1);
			}
		}
		for(int i = 1, current = 0; i < n; i++){
			cout << (current <= i);
			for(int& j : g[i]){
				maximize(current, j - dp[i] - 1);
			}
		}
		cout << "\n";
	}
}