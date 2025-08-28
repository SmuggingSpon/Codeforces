#include<bits/stdc++.h>
#define taskname "2042F"
using namespace std;
typedef long long ll;
const int lim = 2e5 + 5;
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
struct Data{
	ll matrix[5][5];
	Data(){
		memset(matrix, -0x0f, sizeof(matrix));
		this->matrix[0][0] = this->matrix[2][2] = this->matrix[4][4] = 0;
	}
};
int n, a[lim], b[lim];
Data st[lim << 2];
Data init(ll a, ll b){
	Data ans;
	ans.matrix[1][1] = ans.matrix[3][3] = a;
	ans.matrix[0][2] = ans.matrix[2][4] = a + (b << 1LL);
	ans.matrix[0][1] = ans.matrix[1][2] = ans.matrix[2][3] = ans.matrix[3][4] = a + b;
	return ans;
}
Data merge(Data a, Data b){
	Data ans;
	for(int i = 0; i < 5; i++){
		for(int j = i; j < 5; j++){
			for(int k = i; k <= j; k++){
				maximize(ans.matrix[i][j], a.matrix[i][k] + b.matrix[k][j]);
			}
		}
	}
	return ans;
}
void update(int id, int l, int r, int p, int x, bool is_a){
	if(l == r){
		if(is_a){
			st[id] = init(a[p] = x, b[p]);
		}
		else{
			st[id] = init(a[p], b[p] = x);
		}
		return;
	}
	int m = (l + r) >> 1;
	if(m < p){
		update(id << 1 | 1, m + 1, r, p, x, is_a);
	}
	else{
		update(id << 1, l, m, p, x, is_a);
	}
	st[id] = merge(st[id << 1], st[id << 1 | 1]);
}
Data get(int id, int l, int r, int u, int v){
	if(l > v || r < u){
		return Data();
	}
	if(u <= l && v >= r){
		return st[id];
	}
	int m = (l + r) >> 1;
	return merge(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
}
void build(int id, int l, int r){
	if(l == r){
		st[id] = init(a[l], b[l]);
		return;
	}	
	int m = (l + r) >> 1;
	build(id << 1, l, m);
	build(id << 1 | 1, m + 1, r);
	st[id] = merge(st[id << 1], st[id << 1 | 1]);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}
	build(1, 1, n);
	int q;
	cin >> q;
	for(int _ = 0; _ < q; _++){
		int _t, u, v;
		cin >> _t >> u >> v;
		if(_t == 3){
			cout << get(1, 1, n, u, v).matrix[0][4] << "\n";
		}
		else{
			update(1, 1, n, u, v, _t == 1);
		}
	}
}