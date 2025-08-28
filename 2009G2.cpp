#include<bits/stdc++.h>
#define taskname "2009G2"
using namespace std;
typedef long long ll;
const int lim = 2e5 + 5;
int a[lim], cnt[lim << 1], lazy[lim << 2];
ll st[lim << 2];
multiset<int>s;
void add(int i){
	s.insert(++cnt[i]);
	if(cnt[i] > 1){
		s.erase(s.find(cnt[i] - 1));
	}
}
void sub(int i){
	s.erase(s.find(cnt[i]));
	if(--cnt[i] > 0){
		s.insert(cnt[i]);
	}
}
void push_down(int id, int l, int r, int m){
	if(lazy[id] != -1){
		st[id << 1] = 1LL * (lazy[id << 1] = lazy[id << 1 | 1] = lazy[id]) * (m - l + 1);
		st[id << 1 | 1] = 1LL * lazy[id] * (r - m);
		lazy[id] = -1;
	}
}
void apply(int id, int l, int r, int u, int v, int x){
	if(l > v || r < u){
		return;
	}
	if(u <= l && v >= r){
		st[id] = 1LL * (lazy[id] = x) * (r - l + 1);
		return;
	}
	int m = (l + r) >> 1;
	push_down(id, l, r, m);
	apply(id << 1, l, m, u, v, x);
	apply(id << 1 | 1, m + 1, r, u, v, x);
	st[id] = st[id << 1] + st[id << 1 | 1];
}
ll get(int id, int l, int r, int u, int v){
	if(l > v || r < u){
		return 0;
	}
	if(u <= l && v >= r){
		return st[id];
	}
	int m = (l + r) >> 1;
	push_down(id, l, r, m);
	return get(id << 1, l, m, u, v) + get(id << 1 | 1, m + 1, r, u, v);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, k, q;
		cin >> n >> k >> q;
		s.clear();
		fill(cnt, cnt + (n << 1) + 1, 0);
		vector<int>a(n + 1), f(n - k + 2);
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			add(a[i] + n - i);
			if(i >= k){
				f[i - k + 1] = *s.rbegin();
				sub(a[i - k + 1] + n - (i - k + 1));
			}
		}
		vector<vector<pair<int, int>>>query(n + 1);
		vector<int>near_r(n - k + 2);
		stack<int>_st;
		for(int i = n - k + 1; i > 0; _st.push(i--)){
			while(!_st.empty() && f[_st.top()] < f[i]){
				_st.pop();
			}
			near_r[i] = (_st.empty() ? n - k + 2 : _st.top());
		}
		for(int _i = 0; _i < q; _i++){
			int l, r;
			cin >> l >> r;
			query[l].emplace_back(r -= k - 1, _i);
		}
		fill(st + 1, st + (n << 2) + 1, 0);
		fill(lazy + 1, lazy + (n << 2) + 1, -1);
		vector<ll>ans(q);
		for(int i = n - k + 1; i > 0; i--){
			apply(1, 1, n - k + 1, i, near_r[i] - 1, f[i]);
			for(auto& [r, index] : query[i]){
				ans[index] = 1LL * k * (r - i + 1) - get(1, 1, n - k + 1, i, r);
			}
		}
		for(ll& x : ans){
			cout << x << "\n";
		}
	}
}