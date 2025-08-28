#include<bits/stdc++.h>
#define taskname "981E"
using namespace std;
const int lim = 1e4 + 5;
bitset<lim>dp;
vector<int>st[lim << 2];
int n, q;
void update(int id, int l, int r, int u, int v, int x){
	if(l > v || r < u){
		return;
	}
	if(u <= l && v >= r){
		st[id].emplace_back(x);
		return;
	}
	int m = (l + r) >> 1;
	update(id << 1, l, m, u, v, x);
	update(id << 1 | 1, m + 1, r, u, v, x);
}
void dfs(int id, int l, int r, bitset<lim>current){
	for(int& x : st[id]){
		current |= current << x;
	}
	if(l == r){
		dp |= current;
		return;
	}
	int m = (l + r) >> 1;
	dfs(id << 1, l, m, current);
	dfs(id << 1 | 1, m + 1, r, current);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n >> q;
	for(int _ = 0; _ < q; _++){
		int l, r, x;
		cin >> l >> r >> x;
		update(1, 1, n, l, r, x);
	}
	dp.reset();
	dp.set(0);
	dfs(1, 1, n, dp);
	vector<int>ans;
	for(int i = 1; i <= n; i++){
		if(dp.test(i)){
			ans.emplace_back(i);
		}
	}
	cout << ans.size() << "\n";
	for(int& x : ans){
		cout << x << " ";
	}
}