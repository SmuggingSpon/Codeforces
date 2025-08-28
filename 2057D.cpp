#include<bits/stdc++.h>
#define taskname "2057D"
using namespace std;
const int lim = 2e5 + 5;
struct Data{
	int max_l, min_l, max_r, min_r, opt;
	Data(){}
	Data(int max_l, int min_l, int max_r, int min_r, int opt){
		this->max_l = max_l;
		this->min_l = min_l;
		this->max_r = max_r;
		this->min_r = min_r;
		this->opt = opt;
	}
};
Data merge(Data a, Data b){
	return Data(max(a.max_l, b.max_l), max(a.min_l, b.min_l), max(a.max_r, b.max_r), max(a.min_r, b.min_r), max(max(a.opt, b.opt), max(a.max_l + b.min_r, a.min_l + b.max_r)));
}
int n, q, a[lim];
Data st[lim << 2];
void build(int id, int l, int r){
	if(l == r){
		st[id] = Data(a[l] + l, l - a[l], a[l] - r, -a[l] - r, 0);
		return;
	}
	int m = (l + r) >> 1;
	build(id << 1, l, m);
	build(id << 1 | 1, m + 1, r);
	st[id] = merge(st[id << 1], st[id << 1 | 1]);
}
void update(int id, int l, int r, int p){
	if(l == r){
		st[id] = Data(a[l] + l, l - a[l], a[l] - r, -a[l] - r, 0);
		return;
	}
	int m = (l + r) >> 1;
	if(m < p){
		update(id << 1 | 1, m + 1, r, p);
	}
	else{
		update(id << 1, l, m, p);
	}
	st[id] = merge(st[id << 1], st[id << 1 | 1]);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		cin >> n >> q;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		build(1, 1, n);
		cout << st[1].opt << "\n";
		for(int __ = 0; __ < q; __++){
			int p, x;
			cin >> p >> x;
			a[p] = x;
			update(1, 1, n, p);
			cout << st[1].opt << "\n";
		}
	}
}
