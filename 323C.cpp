#include<bits/stdc++.h>
#define taskname "323C"
using namespace std;
const int lim = 1e6 + 5;
const int LIM = 3e7;
struct Data{
	int l, r, sum;
	Data(){
		this->sum = 0;
	}
};
Data st[LIM];
int n, q, x = 0, st_size = 0, p[lim];
void update(int id, int l, int r, const int p){
	if(l == r){
		st[id].sum++;
		return;
	}
	int m = (l + r) >> 1;
	if(m < p){
		st[++st_size] = st[st[id].r]; 
		update(st[id].r = st_size, m + 1, r, p);
	}
	else{
		st[++st_size] = st[st[id].l];
		update(st[id].l = st_size, l, m, p);
	}
	st[id].sum = st[st[id].l].sum + st[st[id].r].sum;
}
void build(int id, int l, int r){
	if(l == r){
		return;
	}
	int m = (l + r) >> 1;
	build(st[id].l = ++st_size, l, m);
	build(st[id].r = ++st_size, m + 1, r);
}
int get(int id, int l, int r, const int u, const int v){
	if(l > v || r < u){
		return 0;
	}
	if(u <= l && v >= r){
		return st[id].sum;
	}
	int m = (l + r) >> 1;
	return get(st[id].l, l, m, u, v) + get(st[id].r, m + 1, r, u, v);
}
int f(int z){
	return (z - 1 + x) % n + 1;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n;
	st_size = n;
	build(0, 1, n);
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		p[x] = i;
	}
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		st[i] = st[i - 1];
		update(i, 1, n, p[x]);
	}
	cin >> q;
	for(int _ = 0; _ < q; _++, x++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int l1 = f(a), r1 = f(b), l2 = f(c), r2 = f(d);
		if(l1 > r1){
			swap(l1, r1);
		}
		if(l2 > r2){
			swap(l2, r2);
		}
		cout << (x = get(r2, 1, n, l1, r1) - get(l2 - 1, 1, n, l1, r1)) << "\n";
	}
}