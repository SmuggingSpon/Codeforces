#include<bits/stdc++.h>
#define taskname "1900E"
using namespace std;
typedef long long ll;
template<class T>void minimize(T& a, T b){
	if(a > b) a = b;
}
void solve(){
	int n, m;
	cin >> n >> m;
	map<pair<int, int>, int>edge_check;
	vector<vector<int>>e(n + 1);
	vector<int>a(n + 1);
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int _ = 0; _ < m; _++){
		int u, v; 
		cin >> u >> v;
		if(u == v || edge_check[make_pair(u, v)]) continue;
		e[u].emplace_back(v);
		edge_check[make_pair(u, v)] = true;
	}
	
	vector<int>low(n + 1), num(n + 1, 0);
	
	function<void(int)>dfs_1;
	stack<int>st;
	vector<int>color(n + 1);
	vector<bool>out(n + 1, false);
	int time_dfs = 0, cnt_scc = 0;
	
	dfs_1 = [&] (int s){
		num[s] = low[s] = ++time_dfs;
		st.push(s);
		for(int& d : e[s]){
			if(out[d]) continue;
			if(num[d] == 0){
				dfs_1(d);
				minimize(low[s], low[d]);
			}
			else{
				minimize(low[s], num[d]);
			}
		}
		if(low[s] == num[s]){
			cnt_scc++;
			while(st.top() != s){
				color[st.top()] = cnt_scc;
				out[st.top()] = true;
				st.pop();
			}		
			color[s] = cnt_scc;
			out[s] = true;
			st.pop();
		}	
	};
	for(int i = 1; i <= n; i++){
		if(num[i] == 0){
			dfs_1(i);
		}
	}	
	
	vector<vector<int>>g(n + 1);
	edge_check.clear();
	for(int u = 1; u <= n; u++){
		for(int& v : e[u]){
			if(color[u] != color[v] && !edge_check[make_pair(color[u], color[v])]){
				edge_check[make_pair(color[u], color[v])] = true;
				g[color[u]].emplace_back(color[v]);
			}
		}
	}
	
	vector<ll>value(cnt_scc + 1, 0);
	vector<int>len(cnt_scc + 1, 0);
	for(int i = 1; i <= n; i++){
		value[color[i]] += a[i];
		len[color[i]]++;
	}
	
	function<pair<int, ll>(int)>dfs_2;
	vector<pair<int, ll>>dp(cnt_scc + 1, make_pair(-1, 0));
	
	dfs_2 = [&] (int s){
		auto& [length, distance] = dp[s];
		if(length != -1) return dp[s];
		
		length = len[s];
		distance = value[s];
		
		for(int& d : g[s]){
			auto [d_length, d_distance] = dfs_2(d);
			d_length += len[s];
			d_distance += value[s];
			if(d_length > length || (d_length == length && d_distance < distance)){
				length = d_length;
				distance = d_distance;
			}
		}
		return dp[s];
	};
	
	int max_length = 0; ll min_distance;
	
	for(int i = 1; i <= cnt_scc; i++){
		auto [length, distance] = dfs_2(i);
		if(length > max_length || (length == max_length && distance < min_distance)){
			max_length = length;
			min_distance = distance;
		}
	}
	cout << max_length << " " << min_distance << "\n";
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