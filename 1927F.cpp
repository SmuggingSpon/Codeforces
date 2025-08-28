#include<bits/stdc++.h>
#define taskname "1927F"
using namespace std;
const int lim = 2e5 + 5;
void solve(){
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>>edge(m);
	vector<vector<int>>e(n + 1);
	for(auto& [u, v, w] : edge){
		cin >> u >> v >> w;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	sort(edge.begin(), edge.end(), [&] (auto a, auto b) -> bool{
		return get<2>(a) > get<2>(b);
	});
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
	int U, V, W;
	for(auto& [u, v, w] : edge){
		if(!merge(u, v)){
			U = u;
			V = v;
			W = w;
		}
	}
	vector<int>ans;
	queue<int>q;
	p.assign(n + 1, -1);
	p[U] = 0;
	q.push(U);
	while(true){
		int u = q.front();
		q.pop();
		if(u == V){
			while(u != U){
				ans.emplace_back(u);
				u = p[u];
			}
			ans.emplace_back(u);
			break;
		}
		for(int& v : e[u]){
			if((u != U || v != V) && p[v] == -1){
				p[v] = u;
				q.push(v);
			}
		}
	}	
	cout << W << " " << ans.size() << "\n";
	for(int& x : ans){
		cout << x << " ";
	}
	cout << "\n";
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		solve();
	}
}