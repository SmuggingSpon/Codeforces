#include<bits/stdc++.h>
#define taskname "2057E1"
using namespace std;
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
		vector<int>u(m), v(m), w(m), gw(m, 0);
		vector<vector<int>>g(n + 1);
		for(int i = 0; i < m; i++){
			cin >> u[i] >> v[i] >> w[i];
			g[u[i]].emplace_back(i);
			g[v[i]].emplace_back(i);
		}
		vector<int>p(m);
		iota(p.begin(), p.end(), 0);
		sort(p.begin(), p.end(), [&] (int i, int j) -> bool{
			return w[i] > w[j];
		});
		vector<tuple<int, int, int>>query(q);
		for(auto& [a, b, k] : query){
			cin >> a >> b >> k;
		}
		vector<int>ans(q, -1);
		for(int _i = 0; _i < m; _i++){
			int ei = p[_i];
			gw[ei] = 1;
			if(_i == m - 1 || w[p[_i + 1]] != w[ei]){
				vector<vector<int>>d(n + 1, vector<int>(n + 1, -1));
				for(int i = 1; i <= n; i++){
					vector<bool>vis(n + 1, false);
					d[i][i] = 0;
					deque<int>dq;
					dq.push_back(i);
					while(!dq.empty()){
						int U = dq.front();
						dq.pop_front();
						if(vis[U]){
							continue;
						}
						vis[U] = true;
						for(int& j : g[U]){
							int V = u[j] ^ v[j] ^ U;
							if(d[i][V] == -1 || d[i][U] + gw[j] < d[i][V]){
								d[i][V] = d[i][U] + gw[j];
								if(gw[j] == 0){
									dq.push_front(V);
								}
								else{
									dq.push_back(V);
								}
							}
						} 
					}
				}
				for(int i = 0; i < q; i++){
					auto& [a, b, k] = query[i];
					if(d[a][b] < k){
						ans[i] = _i;
					}
				}
			}
		}
		for(int& x : ans){
			cout << w[p[x + 1]] << " ";
		}
		cout << "\n";
	}
}