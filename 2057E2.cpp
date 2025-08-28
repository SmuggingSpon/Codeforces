#include<bits/stdc++.h>
#define taskname "2057E2"
using namespace std;
const int INF = 1e9;
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
		int n, m, q;
		cin >> n >> m >> q;
		vector<tuple<int, int, int>>edge(m);
		vector<vector<int>>d(n + 1, vector<int>(n + 1, INF));
		for(auto& [u, v, w] : edge){
			cin >> u >> v >> w;
			d[u][v] = d[v][u] = 1;
		}
		vector<int>p(n + 1);
		iota(p.begin(), p.end(), 0);
		auto find_set = [&] (int N){
			while(N != p[N]){
				N = p[N] = p[p[N]];
			}
			return N;
		};
		auto merge = [&] (int a, int b){
			if((a = find_set(a)) != (b = find_set(b))){
				p[a] = b;
				return true;
			}
			return false;
		};
		sort(edge.begin(), edge.end(), [&] (auto i, auto j) -> bool{
			return get<2>(i) < get<2>(j);
		});
		for(int i = 1; i <= n; i++){
			d[i][i] = 0;
		}
		for(int k = 1; k <= n; k++){
			for(int u = 1; u <= n; u++){
				for(int v = 1; v <= n; v++){
					minimize(d[u][v], d[u][k] + d[k][v]);
				}
			}
		}
		vector<tuple<int, int, int>>query(q);
		for(auto& [a, b, k] : query){
			cin >> a >> b >> k;
		}
		vector<int>ans(q, -1);
		for(auto& [u, v, w] : edge){
			if(merge(u, v)){
				d[u][v] = d[v][u] = 0;
				for(int i = 1; i <= n; i++){
					for(int j = 1; j <= n; j++){
						minimize(d[i][j], min(d[i][u] + d[v][j], d[i][v] + d[u][j]));
					}
				}
				for(int i = 0; i < q; i++){
					if(ans[i] == -1){
						auto& [a, b, k] = query[i];
						if(d[a][b] < k){
							ans[i] = w;
						}
					}
				}
			}
		}
		for(int& x : ans){
			cout << x << " ";
		}
		cout << "\n";
	}
}