#include<bits/stdc++.h>
#define taskname "2044H"
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, q;
		cin >> n >> q;
		vector<vector<ll>>f(n + 2, vector<ll>(n + 2, 0));
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cin >> f[i][j];
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = n; j > 0; j--){
				f[i][j] += f[i][j + 1];
			}
		}
		vector<vector<ll>>g(n + 2, vector<ll>(n + 2, 0));
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				g[i][j] = g[i - 1][j] + f[i][j] * i;
			}
		}
		for(int i = 1; i < n + 2; i++){
			ll sum = 0;
			for(int j = 1; j < n + 2; j++){
				f[i][j] = (sum += f[i][j]) + f[i - 1][j];
			}
		}
		auto get_f = [&] (int x, int y, int u, int v){
			return f[u][v] - f[u][y - 1] - f[x - 1][v] + f[x - 1][y - 1];
		};
		auto get_poly_g = [&] (int col, int i, int j){
			return g[j][col] - g[i - 1][col] - ll(i) * get_f(i, col, j, col);
		};
		for(int _q = 0; _q < q; _q++){
			int x, y, u, v;
			cin >> x >> y >> u >> v;
			ll ans = get_f(x, y, u, v) - ll(v - y + 1) * get_f(x, v + 1, u, v + 1);
			cout << ans + ll(v - y + 1) * (get_poly_g(y, x, u) - get_poly_g(v + 1, x, u)) << " ";
		}
		cout << "\n";
	}
}