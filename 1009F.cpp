#include<bits/stdc++.h>
#define taskname "1009F"
using namespace std;
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
const int lim = 1e6 + 5;
int n, ans[lim];
pair<int, int>value[lim];
map<int, int>cnt[lim];
vector<int>g[lim];
void dfs(int s, int h = 0, int p = -1){
	cnt[s][h]++;
	value[s] = make_pair(1, -h);
	for(int& d : g[s]){
		if(d != p){
			dfs(d, h + 1, s);
			if(cnt[s].size() < cnt[d].size()){
				swap(cnt[s], cnt[d]);
				swap(value[s], value[d]);
			}
			for(auto& [u, v] : cnt[d]){
				maximize(value[s], make_pair(cnt[s][u] += v, -u));
			}
		}
	}
	ans[s] = -value[s].second - h;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n;
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs(1);
	for(int i = 1; i <= n; i++){
		cout << ans[i] << "\n";
	}
}