#include<bits/stdc++.h>
#define taskname "1118F1"
using namespace std;
const int lim = 3e5 + 5;
int n, ans = 0, cnt[lim][2];
vector<int>g[lim];
void dfs_1(int s, int p = -1){
	for(int& d : g[s]){
		if(d != p){
			dfs_1(d, s);
			cnt[s][0] += cnt[d][0];
			cnt[s][1] += cnt[d][1];
		}
	}
}
void dfs_2(int s, int p = -1){
	for(int& d : g[s]){
		if(d != p){
			if((cnt[d][0] == cnt[1][0] && cnt[d][1] == 0) || (cnt[d][1] == cnt[1][1] && cnt[d][0] == 0)){
				ans++;
			}
			dfs_2(d, s);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n;
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if(x > 0){
			cnt[i][x - 1]++;
		}
	}
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs_1(1);
	dfs_2(1);
	cout << ans;
}