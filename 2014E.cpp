#include<bits/stdc++.h>
#define taskname "2014E"
using namespace std;
typedef long long ll;
const ll INF = 1e18;
template<class T>bool minimize(T& a, T b){
	if(a > b){
		a = b;
		return true;
	}
	return false;
}
struct Data{
	ll w;
	int u;
	bool type;
	friend bool operator <(const Data a, const Data b){
		return a.w > b.w;
	}
	Data(ll _w, int _u, bool _type) : w(_w), u(_u), type(_type) {}
};
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, m, h;
		cin >> n >> m >> h;
		vector<bool>have_horse(n + 1, false);
		for(int i = 0; i < h; i++){
			int x;
			cin >> x;
			have_horse[x] = true;
		}
		vector<vector<pair<int, int>>>g(n + 1);
		for(int i = 0; i < m; i++){
			int u, v, w;
			cin >> u >> v >> w;
			g[u].emplace_back(v, w);
			g[v].emplace_back(u, w);
		}
		auto get_dijkstra = [&] (int vertex){
			vector<vector<ll>>d(n + 1, vector<ll>(2, INF));
			priority_queue<Data>pq;
			pq.emplace(d[vertex][0] = 0, vertex, false);
			if(have_horse[vertex]){
				pq.emplace(d[vertex][1] = 0, vertex, true);
			}
			while(!pq.empty()){
				auto [w, u, type] = pq.top();
				pq.pop();
				if(w == d[u][type]){
					for(auto& [V, W] : g[u]){
						if(type){
							if(minimize(d[V][1], w + (W >> 1))){
								pq.emplace(d[V][1], V, true);
							}
						}
						else{
							if(minimize(d[V][0], w + W)){
								pq.emplace(d[V][0], V, false);
							}
							if(have_horse[V] && minimize(d[V][1], w + W)){
								pq.emplace(d[V][1], V, true);
							}
						}
					}
				}
			}
			return d;
		};
		vector<vector<ll>>d_1 = get_dijkstra(1), d_n = get_dijkstra(n);
		if(d_1[n][0] == INF){
			cout << "-1\n";
			continue;
		}
		ll ans = INF;
		for(int i = 1; i <= n; i++){
			minimize(ans, max(min(d_1[i][0], d_1[i][1]), min(d_n[i][0], d_n[i][1])));
		}
		cout << ans << "\n";
	}
}