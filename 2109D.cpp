#include<bits/stdc++.h>
#define taskname "2109D"
using namespace std;
typedef long long ll;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
const int INF = 2e9;
struct Data{
	int u;
	bool f;
	ll w;
	Data(){}
	Data(int _u, bool _f, ll _w) : u(_u), f(_f), w(_w) {}
	friend bool operator <(const Data a, const Data b){
		return a.w > b.w;
	}
};
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, m, l;
		cin >> n >> m >> l;
		vector<int>mia(2, INF);
		int sa = mia[0] = 0;
		for(int i = 0; i < l; i++){
			int x;
			cin >> x;
			sa += x;
			minimize(mia[x & 1], x);
		}
		vector<vector<int>>g(n + 1);
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		vector<vector<int>>d(n + 1, vector<int>(2, INF));
		queue<pair<int, bool>>q;
		q.emplace(1, false);
		d[1][0] = 0;
		while(!q.empty()){
			auto [u, f] = q.front();
			q.pop();
			for(int& v : g[u]){
				if(d[v][!f] == INF){
					d[v][!f] = d[u][f] + 1;
					q.emplace(v, !f);
				}
			}
		}
		for(int i = 1; i <= n; i++){
			cout << (d[i][0] <= sa - mia[sa & 1] || d[i][1] <= sa - mia[(sa & 1) ^ 1]);
		}
		cout << "\n";
	}
}