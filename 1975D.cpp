#include<bits/stdc++.h>
#define taskname "1975D"
using namespace std;
const int lim = 2e5 + 5;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
int dp_0[lim], dp_1[lim];
vector<int>e[lim];
void dfs(int s, int par = -1){
	vector<int>p = e[s];
	for(int& d : e[s]){
		if(d != par){
			dfs(d, s);
		}
		else{
			p.erase(find(p.begin(), p.end(), par));
		}
	}
	if(p.empty()){
		dp_0[s] = dp_1[s] = 0;
		return;
	}
	dp_0[s] = 0;
	for(int& x : p){
		dp_0[s] += dp_0[x] + 2;
	}
	dp_1[s] = INT_MAX;
	for(int& x : p){
		minimize(dp_1[s], dp_0[s] - dp_0[x] + dp_1[x] - 1);
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
		int n, a, b;
		cin >> n >> a >> b;
		for(int i = 1; i <= n; i++){
			e[i].clear();
		}
		for(int i = 1; i < n; i++){
			int x, y;
			cin >> x >> y;
			e[x].emplace_back(y);
			e[y].emplace_back(x);
		}
		queue<int>q;
		vector<int>_par(n + 1, -1);
		_par[a] = 0;
		q.push(a);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int& v : e[u]){
				if(_par[v] == -1){
					q.push(v);
					_par[v] = u;
				}
			}
		}
		vector<int>path;
		while(b != 0){
			path.emplace_back(b);
			b = _par[b];
		}
		dfs(path[int(path.size()) >> 1]);
		cout << dp_1[path[int(path.size()) >> 1]] + (int(path.size()) >> 1) << "\n";
	}
}