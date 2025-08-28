#include<bits/stdc++.h>
#define taskname "438D"
using namespace std;
typedef long long ll;
const int lim = 1e5 + 5;
pair<int, ll>st[lim << 2];
int n, q, a[lim];
pair<int, ll>merge(pair<int, ll>a, pair<int, ll>b){
	if(a.first == -1){
		return b;
	}
	if(b.first == -1){
		return a;
	}
	return make_pair(max(a.first, b.first), a.second + b.second);
}
void build(int id, int l, int r){
	if(l == r){
		st[id] = make_pair(a[l], a[l]);
		return;
	}
	int m = (l + r) >> 1;
	build(id << 1, l, m);
	build(id << 1 | 1, m + 1, r);
	st[id] = merge(st[id << 1], st[id << 1 | 1]);
}
void update_mod(int id, int l, int r, int u, int v, int x){
	if(l > v || r < u || st[id].first < x){
		return;
	}
	if(l == r){
		st[id].second = (st[id].first %= x);
		return;
	}
	int m = (l + r) >> 1;
	update_mod(id << 1, l, m, u, v, x);
	update_mod(id << 1 | 1, m + 1, r, u, v, x);
	st[id] = merge(st[id << 1], st[id << 1 | 1]);
}
void update_assign(int id, int l, int r, int p, int x){
	if(l == r){
		st[id] = make_pair(x, x);
		return;
	}
	int m = (l + r) >> 1;
	if(m < p){
		update_assign(id << 1 | 1, m + 1, r, p, x);
	}
	else{
		update_assign(id << 1, l, m, p, x);
	}
	st[id] = merge(st[id << 1], st[id << 1 | 1]);
}
pair<int, ll>get(int id, int l, int r, int u, int v){
	if(l > v || r < u){
		return make_pair(-1, 0LL);
	}
	if(u <= l && v >= r){
		return st[id];
	}
	int m = (l + r) >> 1;
	return merge(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	build(1, 1, n);
	for(int _ = 0; _ < q; _++){
		int _t;
		cin >> _t;
		if(_t == 1){
			int l, r;
			cin >> l >> r;
			cout << get(1, 1, n, l, r).second << "\n";
		}
		else if(_t == 2){
			int l, r, x;
			cin >> l >> r >> x;
			update_mod(1, 1, n, l, r, x);			
		}
		else{
			int k, x;
			cin >> k >> x;
			update_assign(1, 1, n, k, x);
		}
	}
}