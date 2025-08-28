#include<bits/stdc++.h>
#define taskname "1905D"
#define int long long
using namespace std;
typedef long long ll;
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
const int lim = 1e6 + 5;
const int LIM = lim << 2;
ll sum[LIM];
int n, a[lim], p[lim], laz[LIM];
bitset<LIM>mark;
void push_down(int id, int l, int r, int m){
	if(mark.test(id)){
		mark.reset(id);
		sum[id << 1] = 1LL * laz[id] * (m - l + 1); 
		sum[(id << 1) | 1] = 1LL * laz[id] * (r - m);
		laz[id << 1] = laz[(id << 1) | 1] = laz[id]; 
		mark[id << 1] = mark[(id << 1) | 1] = true;  		
		laz[id] = 0; 
	}
	else if(laz[id] != 0){
		sum[id << 1] += 1LL * laz[id] * (m - l + 1);
		sum[(id << 1) | 1] += 1LL * laz[id] * (r - m);
		laz[id << 1] += laz[id]; 
		laz[(id << 1) | 1] += laz[id]; 
		laz[id] = 0;
	}
}
void assign(int id, int l, int r, int u, int v){
	if(u > r || v < l) return;
	if(u <= l && v >= r){
		mark.set(id);
		sum[id] = laz[id] = 0;
		return;
	}
	int m = (l + r) >> 1;
	push_down(id, l, r, m); 
	assign(id << 1, l, m, u, v);
	assign((id << 1) | 1, m + 1, r, u, v); 
	sum[id] = sum[id << 1] + sum[(id << 1) | 1];
}
void update(int id, int l, int r, int p, int x){
	if(l == r){
		sum[id] = x;		
	}
	else{
		int m = (l + r) >> 1;
		if(m < p){
			update((id << 1) | 1, m + 1, r, p, x);
		}
		else{
			update(id << 1, l, m, p, x);
		}
		sum[id] = sum[id << 1] + sum[(id << 1) | 1];
	}
}
void update(int id, int l, int r, int u, int v, int x){
	if(u > r || v < l) return;
	if(u <= l && v >= r){
		laz[id] += x; 
		sum[id] += 1LL * x * (r - l + 1); 
		return;
	}
	int m = (l + r) >> 1;
	push_down(id, l, r, m); 
	update(id << 1, l, m, u, v, x);
	update((id << 1) | 1, m + 1, r, u, v, x); 
	sum[id] = sum[id << 1] + sum[(id << 1) | 1];
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			p[++a[i]] = i;
		}
		fill(sum + 1, sum + (n << 2) + 1, 0);
		fill(laz + 1, laz + (n << 2) + 1, 0);
		for(int i = n << 2; i > 0; i--){
			mark.reset(i);
		}
		for(int i = 1, max_value = 0; i <= n; i++){
			maximize(max_value, p[i]);
			update(1, 1, n, i, n - max_value);
		}
		ll ans = sum[1];
		for(int i = 1; i < n; i++){
			if(a[i] == 1){
				assign(1, 1, n, 1, n);
			}
			else{
				update(1, 1, n, 1, a[i] - 1, 1);
				assign(1, 1, n, a[i], n);
			}
			maximize(ans, sum[1]);
		}
		cout << ans + n << "\n";
	}
}