#include<bits/stdc++.h>
#define taskname "911G"
using namespace std;
const int lim = 2e5 + 5;
const int LIM = 105;
int n, q, a[lim], st[lim << 2][LIM];
void push_down(int id){
	for(int i = 1; i < LIM; i++){
		st[id << 1][i] = st[id][st[id << 1][i]];
		st[id << 1 | 1][i] = st[id][st[id << 1 | 1][i]];
	}	
	iota(st[id], st[id] + LIM, 0);
}
void update(int id, int l, int r, int u, int v, int x, int y){
	if(l > v || r < u){
		return;
	}
	if(u <= l && v >= r){
		for(int i = 1; i < LIM; i++){
			if(st[id][i] == x){
				st[id][i] = y;
			}
		}
		return;
	}
	int m = (l + r) >> 1;
	push_down(id);
	update(id << 1, l, m, u, v, x, y);
	update(id << 1 | 1, m + 1, r, u, v, x, y);
}
void solve(int id, int l, int r){
	if(l == r){
		cout << st[id][a[l]] << " ";
		return;
	}
	int m = (l + r) >> 1;
	push_down(id);
	solve(id << 1, l, m);
	solve(id << 1 | 1, m + 1, r);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	for(int i = (lim << 2) - 1; i > 0; i--){
		iota(st[i], st[i] + LIM, 0);
	}
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	cin >> q;
	for(int _ = 0; _ < q; _++){
		int l, r, x, y;
		cin >> l >> r >> x >> y;
		update(1, 1, n, l, r, x, y);
	}
	solve(1, 1, n);
}
