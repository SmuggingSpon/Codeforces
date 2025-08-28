#include<bits/stdc++.h>
#define taskname "2094F"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>ans(n + 1, vector<int>(m + 1));
		if(__gcd(n, k) > 1){
			for(int i = 1, start = 1, g = __gcd(n, k); i <= m; i++){
				for(int j = 1; j <= n; j += g, start = (start + g) % k){
					vector<int>app;
					if(i & 1){
						for(int t = 0; t < g; t++){
							app.emplace_back(start + t);
						}
					}
					else{
						for(int t = 1; t < g; t++){
							app.emplace_back(start + t);
						}
						app.emplace_back(start);
					}
					for(int t = 0; t < g; t++){
						ans[j + t][i] = app[t];
					}
				}
			}
		}
		else{
			for(int i = 1, start = 1, g = __gcd(m, k); i <= n; i++){
				for(int j = 1; j <= m; j += g, start = (start + g) % k){
					vector<int>app;
					if(i & 1){
						for(int t = 0; t < g; t++){
							app.emplace_back(start + t);
						}
					}
					else{
						for(int t = 1; t < g; t++){
							app.emplace_back(start + t);
						}
						app.emplace_back(start);
					}
					for(int t = 0; t < g; t++){
						ans[i][j + t] = app[t];
					}
				}
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
	}
}