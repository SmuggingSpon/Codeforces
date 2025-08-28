#include<bits/stdc++.h>
#define taskname "1076D"
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
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int n, m, k;
	cin >> n >> m >> k;
	vector<int>u(m), v(m), w(m);
	vector<vector<int>>g(n + 1);
	for(int i = 0; i < m; i++){
		cin >> u[i] >> v[i] >> w[i];
		g[u[i]].emplace_back(i);
		g[v[i]].emplace_back(i);
	}
	vector<ll>d(n + 1, INF);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>pq;
	pq.emplace(d[1] = 0, 1);
	while(!pq.empty()){
		auto [W, U] = pq.top();
		pq.pop();
		if(W == d[U]){
			for(int& i : g[U]){
				int V = u[i] ^ v[i] ^ U;
				if(minimize(d[V], W + w[i])){
					pq.emplace(d[V], V);
				}
			}
		}
	}
	vector<bool>vis(n + 1, false);
	vector<int>ans;
	function<void(int)>dfs;
	dfs = [&] (int U){
		vis[U] = true;
		for(int& i : g[U]){
			int V = u[i] ^ v[i] ^ U;
			if(!vis[V] && d[V] == d[U] + w[i]){
				if(ans.size() < k){
					ans.emplace_back(i);
				}
				dfs(V);
			}
		}
	};
	dfs(1);
	cout << ans.size() << "\n";
	for(int& i : ans){
		cout << i + 1 << " ";
	}
	cout << "\n";
}