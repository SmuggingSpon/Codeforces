#include<bits/stdc++.h>
#define taskname "522D"
using namespace std;
const int lim = 5e5 + 5;
const int INF = 1e9;
int a[lim], st[lim << 2], ans[lim];
vector<pair<int, int>>query[lim];
map<int, int>pos;
void update(int id, int l, int r, int p, int x){
	if(l == r){
		st[id] = x;
		return;
	}
	int m = (l + r) >> 1;
	if(m < p){
		update(id << 1 | 1, m + 1, r, p, x);
	}
	else{
		update(id << 1, l, m, p, x);
	}
	st[id] = min(st[id << 1], st[id << 1 | 1]);
}
int get(int id, int l, int r, int u, int v){
	if(l > v || r < u){
		return INF;
	}
	if(u <= l && v >= r){
		return st[id];
	}
	int m = (l + r) >> 1;
	return min(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= q; i++){
		int l, r;
		cin >> l >> r;
		query[r].emplace_back(l, i);
	}
	fill(st + 1, st + (n << 2), INF);
	for(int i = 1; i <= n; i++){
		if(pos[a[i]] > 0){
			update(1, 1, n, pos[a[i]], i - pos[a[i]]);
		}
		pos[a[i]] = i;
		for(auto& [l, I] : query[i]){
			ans[I] = get(1, 1, n, l, i);
		}
	}
	for(int i = 1; i <= q; i++){
		cout << (ans[i] == INF ? -1 : ans[i]) << "\n";
	}
}