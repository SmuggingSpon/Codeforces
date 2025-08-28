#include<bits/stdc++.h>
#define taskname "1179C"
using namespace std;
const int lim = 3e5 + 5;
const int LIM = 1e6 + 5;
int n, m, a[lim], b[lim], st[(LIM << 2) + 10], lazy[(LIM << 2) + 10];
void push_down(int id){
	st[id << 1] += lazy[id];
	lazy[id << 1] += lazy[id];
	st[id << 1 | 1] += lazy[id];
	lazy[id << 1 | 1] += lazy[id];
	lazy[id] = 0;
}
void update(int id, int l, int r, int u, int v, int x){
	if(l > v || r < u){
		return;
	}
	if(u <= l && v >= r){
		st[id] += x;
		lazy[id] += x;
		return;
	}
	int m = (l + r) >> 1;
	push_down(id);
	update(id << 1, l, m, u, v, x);
	update(id << 1 | 1, m + 1, r, u, v, x);
	st[id] = max(st[id << 1], st[id << 1 | 1]);
}
int walk(){
	int id = 1, l = 1, r = LIM;
	while(l < r){
		int m = (l + r) >> 1;
		push_down(id);
		id <<= 1;
		if(st[id | 1] > 0){
			id |= 1;
			l = m + 1;
		}
		else{
			r = m;
		}
	}
	return st[id] < 1 ? -1 : l;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n >> m;
	memset(st, 0, sizeof(st));
	memset(lazy, 0, sizeof(lazy));
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		update(1, 1, LIM, 1, a[i], 1);
	}
	for(int i = 1; i <= m; i++){
		cin >> b[i];
		update(1, 1, LIM, 1, b[i], -1);
	}
	int q;
	cin >> q;
	for(int _ = 0; _ < q; _++){
		int type, i, x;
		cin >> type >> i >> x;
		if(type == 1){
			update(1, 1, LIM, 1, a[i], -1);
			update(1, 1, LIM, 1, a[i] = x, 1);
		}
		else{
			update(1, 1, LIM, 1, b[i], 1);
			update(1, 1, LIM, 1, b[i] = x, -1);
		}
		cout << walk() << "\n";
	}
}