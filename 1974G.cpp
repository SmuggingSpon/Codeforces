#include<bits/stdc++.h>
#define taskname "1974G"
using namespace std;
const int lim = 2e5 + 5;
int n, x, st[lim << 2], lazy[lim << 2];
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
		lazy[id] += x;
		st[id] += x;
		return;
	}
	push_down(id);
	int m = (l + r) >> 1;
	update(id << 1, l, m, u, v, x);
	update(id << 1 | 1, m + 1, r, u, v, x);
	st[id] = min(st[id << 1], st[id << 1 | 1]);
}
int get(int id, int l, int r, int u, int v){
	if(l > v || r < u){
		return INT_MAX;
	}
	if(u <= l && v >= r){
		return st[id];
	}
	push_down(id);
	int m = (l + r) >> 1;
	return min(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		cin >> n >> x;
		vector<int>c(n);
		for(int i = 0; i < n; i++){
			cin >> c[i];
		}
		fill(st + 1, st + (n << 2), 0);
		fill(lazy + 1, lazy + (n << 2), 0);
		for(int i = 1; i < n; i++){
			update(1, 1, n - 1, i, n - 1, x);
		}
		vector<int>p(n - 1);
		iota(p.begin(), p.end(), 1);
		sort(p.begin(), p.end(), [&] (int i, int j) -> bool{
			return c[i] < c[j];
		});
		int ans = 0;
		for(int& index : p){
			if(get(1, 1, n - 1, index, n - 1) >= c[index]){
				update(1, 1, n - 1, index, n - 1, -c[index]);
				ans++;
			}
		}
		cout << ans << "\n";
	}
}