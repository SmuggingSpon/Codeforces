#include<bits/stdc++.h>
#define taskname "145E"
using namespace std;
const int lim = 1e6 + 5;
struct Data{
	int cnt_4, cnt_7, icr, dcr;
	Data(){}
	Data(int _cnt_4, int _cnt_7, int _icr, int _dcr) : cnt_4(_cnt_4), cnt_7(_cnt_7), icr(_icr), dcr(_dcr) {}
};
int n, m;
string s;
Data st[lim << 2];
bitset<lim << 2>mark;
Data merge(Data a, Data b){
	return Data(a.cnt_4 + b.cnt_4, a.cnt_7 + b.cnt_7, max(a.icr + b.cnt_7, a.cnt_4 + b.icr), max(a.dcr + b.cnt_4, a.cnt_7 + b.dcr));
}
void build(int id, int l, int r){
	if(l == r){
		st[id] = Data(s[l - 1] == '4', s[l - 1] == '7', 1, 1);
		return;
	}
	int m = (l + r) >> 1;
	build(id << 1, l, m);
	build(id << 1 | 1, m + 1, r);
	st[id] = merge(st[id << 1], st[id << 1 | 1]);
}
void node_flip(int id){
	mark.flip(id);
	swap(st[id].cnt_4, st[id].cnt_7);
	swap(st[id].icr, st[id].dcr);
}
void push_down(int id){
	if(mark.test(id)){
		node_flip(id << 1);
		node_flip(id << 1 | 1);
		mark.reset(id);
	}
}
void update(int id, int l, int r, int u, int v){
	if(l > v || r < u){
		return;
	}
	if(u <= l && v >= r){
		node_flip(id);
		return;
	}
	push_down(id);
	int m = (l + r) >> 1;
	update(id << 1, l, m, u, v);
	update(id << 1 | 1, m + 1, r, u, v);
	st[id] = merge(st[id << 1], st[id << 1 | 1]);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n >> m >> s;
	mark.reset();
	build(1, 1, n);
	for(int _ = 0; _ < m; _++){
		string type;
		cin >> type;
		if(type == "switch"){
			int l, r;
			cin >> l >> r;
			update(1, 1, n, l, r);
		}
		else{
			cout << st[1].icr << "\n";
		}
	}
}