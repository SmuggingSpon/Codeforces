#include<bits/stdc++.h>
#define taskname "786B"
using namespace std;
typedef long long ll;
template<class T>bool minimize(T& a, T b){
	if(a > b){
		a = b;
		return true;
	}
	return false;
}
const ll INF = 1e18;
const int lim = 1e5 + 5;
int n, q, s;
bitset<lim << 2>leaf, vis;
vector<pair<int, int>>g[lim << 2];
void build(int id, int l, int r){
	if(l == r){
		leaf.set(id);
		return;
	}
	int m = (l + r) >> 1;
	g[id].emplace_back(id << 1, 0);
	g[id].emplace_back(id << 1 | 1, 0);
	build(id << 1, l, m);
	build(id << 1 | 1, m + 1, r);
}
void move(int id, int l, int r, int u, int v, vector<int>& index){
	if(l > v || r < u){
		return;
	}
	if(u <= l && v >= r){
		index.emplace_back(id);
		return;
	}
	int m = (l + r) >> 1;
	move(id << 1, l, m, u, v, index);
	move(id << 1 | 1, m + 1, r, u, v, index);
}
vector<int>get_range(int l, int r){
	vector<int>index;
	move(1, 1, n, l, r, index);
	return index;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n >> q >> s;
	leaf.reset();
	build(1, 1, n);
	for(int i = 0; i < q; i++){
		int type;
		cin >> type;
		if(type == 1){
			int u, v, w;
			cin >> u >> v >> w;
			vector<int>U = get_range(u, u), V = get_range(v, v);
			g[get_range(u, u)[0]].emplace_back(get_range(v, v)[0], w);
		}
		else{
			int u, l, r, w;
			cin >> u >> l >> r >> w;
			vector<int>U = get_range(u, u), V = get_range(l, r);
			if(type == 3){
				swap(U, V);
			}
			for(int& I : U){
				for(int& J : V){
					g[I].emplace_back(J, w);
				}
			}
		}
	}
	vector<ll>dp(n << 2, INF);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>pq;
	int temp = get_range(s, s)[0];
	pq.emplace(dp[temp] = 0, temp);
	vis.reset();
	while(!pq.empty()){
		auto [W, u] = pq.top();
		pq.pop();
		if(W == dp[u]){
			for(auto& [v, ew] : g[u]){
				if(minimize(dp[v], W + ew)){
					pq.emplace(dp[v], v);
				}
			}
			while(u > 0 && !vis.test(u)){
				for(auto& [v, ew] : g[u]){
					if(leaf.test(v) && ew > 0 && minimize(dp[v], W + ew)){
						pq.emplace(dp[v], v);
					}
				}				
				vis.set(u);
				u >>= 1;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		int u = get_range(i, i)[0];
		ll ans = INF;
		while(u > 0){
			minimize(ans, dp[u]);
			u >>= 1;
		}
		cout << (ans == INF ? -1LL : ans) << " ";
	}
}