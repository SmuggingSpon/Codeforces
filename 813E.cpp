#include<bits/stdc++.h>
#define taskname "813E"
using namespace std;
const int lim = 1e5 + 5;
struct Data{
	int cnt, L, R;
	Data(int _cnt, int _L, int _R) : cnt(_cnt), L(_L), R(_R) {}
};
vector<Data>st;
vector<int>p[lim];
int n, k;
void build(int id, int l, int r){
	if(l == r){
		return;
	}
	st[id].L = st.size();
	st.emplace_back(0, -1, -1);;
	st[id].R = st.size();
	st.emplace_back(0, -1, -1);
	int m = (l + r) >> 1;
	build(st[id].L, l, m);
	build(st[id].R, m + 1, r);
}
void update(int id, int l, int r, int p, int x){
	if(l == r){
		st[id].cnt += x;
		return;
	}
	int m = (l + r) >> 1;
	if(m < p){
		st.emplace_back(st[st[id].R]);
		update(st[id].R = int(st.size()) - 1, m + 1, r, p, x);
	}
	else{
		st.emplace_back(st[st[id].L]);
		update(st[id].L = int(st.size()) - 1, l, m, p, x);
	}
	st[id].cnt = st[st[id].L].cnt + st[st[id].R].cnt;
}
int get(int id, int l, int r, int u, int v){
	if(l > v || r < u){
		return 0;
	}
	if(u <= l && v >= r){
		return st[id].cnt;
	}
	int m = (l + r) >> 1;
	return get(st[id].L, l, m, u, v) + get(st[id].R, m + 1, r, u, v);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n >> k;
	for(int i = 0; i <= n; i++){
		st.emplace_back(0, -1, -1);
	}
	build(0, 1, n);
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		st[i] = st[i - 1];
		if(p[x].size() >= k){
			update(i, 1, n, p[x][int(p[x].size()) - k], -1);
		}
		p[x].emplace_back(i);
		update(i, 1, n, i, 1);
	}
	int q;
	cin >> q;
	for(int _ = 0, last = 0; _ < q; _++){
		int l, r;
		cin >> l >> r;
		if((l = (l + last) % n + 1) > (r = (r + last) % n + 1)){
			swap(l, r);
		}
		cout << (last = get(r, 1, n, l, r)) << "\n";
	}
}