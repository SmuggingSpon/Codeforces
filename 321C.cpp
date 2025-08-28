#include<bits/stdc++.h>
#define taskname "321C"
using namespace std;
const int lim = 1e5 + 5;
vector<int>g[lim];
char ans[lim];
bitset<lim>used;
int n, cnt_child[lim];
void dfs(int s, int p){
	cnt_child[s] = 1;
	for(int i = 0; i < g[s].size(); i++){
		int d = g[s][i];
		if(d != p && !used.test(d)){
			dfs(d, s);
			cnt_child[s] += cnt_child[d];
		}
	}
}
void centroid_decomposition(int s, int p, char c){
	dfs(s, p);
	int N = cnt_child[s];
	while(true){
		bool change = false;
		for(int i = 0; i < g[s].size(); i++){
			int d = g[s][i];
			if(d != p && !used.test(d) && cnt_child[d] > (N >> 1)){
				p = s;
				s = d;
				change = true;
				break;
			}
		}
		if(!change){
			break;
		}
	}
	ans[s] = c;
	used.set(s);
	for(int i = 0; i < g[s].size(); i++){
		int d = g[s][i];
		if(!used.test(d)){
			centroid_decomposition(d, s, c + 1);
		}
	}
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
		g[u].push_back(v);
		g[v].push_back(u);
	}
	used.reset();
	centroid_decomposition(1, -1, 'A');
	for(int i = 1; i <= n; i++){
		cout << ans[i] << " ";
	}
}