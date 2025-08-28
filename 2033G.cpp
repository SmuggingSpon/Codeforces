#include<bits/stdc++.h>
#define taskname "2033G"
using namespace std;
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
const int INF = 1e9;
const int lim = 2e5 + 5;
vector<int>g[lim];
pair<int, int>up[lim][18];
int n, q, h[lim], max_h[lim];
void dfs_1(int s){
	int max_1 = -1, max_2 = -1;
	max_h[s] = h[s];
	for(int& d : g[s]){
		if(d != up[s][0].first){
			h[d] = h[up[d][0].first = s] + 1; 
			dfs_1(d);
			maximize(max_h[s], max_h[d]);
			if(max_1 == -1 || max_h[d] > max_h[max_1]){
				max_2 = max_1;
				max_1 = d;
			}
			else if(max_2 == -1 || max_h[d] > max_h[max_2]){
				max_2 = d;
			}
		}
	}
	for(int& d : g[s]){
		if(d != up[s][0].first){
			up[d][0].second = (max_1 != d ? max_h[max_1] - (h[s] << 1) : ((max_2 == -1 ? h[s] : max_h[max_2]) - (h[s] << 1)));
		}
	}
}
void dfs_2(int s){
	for(int i = 1; i < 18; i++){
		up[s][i].first = up[up[s][i - 1].first][i - 1].first;
		up[s][i].second = max(up[s][i - 1].second, up[up[s][i - 1].first][i - 1].second);
	}
	for(int& d : g[s]){
		if(d != up[s][0].first){
			dfs_2(d);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	for(int i = 0; i < 18; i++){
		up[0][i] = make_pair(0, -INF);
	}
	h[1] = 1;
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		cin >> n;
		for(int i = 1; i <= n; i++){
			g[i].clear();
			up[i][0] = make_pair(0, -INF);
		}
		for(int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		dfs_1(1);
		dfs_2(1);
		cin >> q;
		for(int _q = 0; _q < q; _q++){
			int v, k;
			cin >> v >> k;
			int ans = max_h[v] - h[v], temp = h[v];
			for(int i = 0; i < 18; i++){
				if(1 << i & k){
					maximize(ans, temp + up[v][i].second);
					v = up[v][i].first;
				}
			}
			cout << ans << " ";
		}
		cout << "\n";
	}
}