#include<bits/stdc++.h>
#define taskname "1916E"
using namespace std;
typedef long long ll;
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
const int lim = 3e5 + 5;
const int INF = 1e9;
set<int>s[lim];
vector<int>e[lim];
int n, time_dfs, st[lim << 2], lazy[lim << 2], a[lim], h[lim], low[lim], tail[lim], p[lim], p_low[lim];
void dfs(int s){
	p_low[low[s] = ++time_dfs] = s;
	for(int& d : e[s]){
		h[d] = h[s] + 1;
		dfs(d);
	}
	tail[s] = time_dfs;
}
void push_down(int id){
	int T = lazy[id];
	lazy[id] = 0;
	st[id <<= 1] += T;
	lazy[id] += T;
	st[id |= 1] += T;
	lazy[id] += T;
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
	push_down(id);
	int m = (l + r) >> 1;
	update(id << 1, l, m, u, v, x);
	update((id << 1) | 1, m + 1, r, u, v, x);
	st[id] = max(st[id << 1], st[(id << 1) | 1]);
}
int get(int id, int l, int r, int u, int v){
	if(l > v || r < u){
		return 0;
	}
	if(u <= l && v >= r){
		return st[id];
	}
	push_down(id);
	int m = (l + r) >> 1;
	return max(get(id << 1, l, m, u, v), get((id << 1) | 1, m + 1, r, u, v));
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		cin >> n;
		for(int i = 1; i <= n; i++){
			s[i].clear();
			e[i].clear();
		}
		for(int i = 1; i < n; ){
			int x;
			cin >> x;
			e[x].emplace_back(++i);
		}
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		if(n == 1){
			cout << "1\n";
			continue;
		}
		ll ans = time_dfs = 0;
		dfs(1);
		fill(st + 1, st + (n << 2) + 1, 0);
		fill(lazy + 1, lazy + (n << 2) + 1, 0);
		iota(p + 1, p + n + 1, 1);
		sort(p + 1, p + n + 1, [&] (int i, int j) -> bool{
			return h[i] > h[j];
		});
		for(int _i = 1; _i <= n; _i++){
			int root = p[_i];
			stack<int>st;
			for(auto it = s[a[root]].lower_bound(low[root]); it != s[a[root]].end() && *it <= tail[root]; it = next(it)){
				update(1, 1, n, *it, tail[p_low[*it]], -1);
				st.push(*it);
			}
			while(!st.empty()){
				s[a[root]].erase(st.top());
				st.pop();
			}
			s[a[root]].insert(low[root]);
			update(1, 1, n, low[root], tail[root], 1);
			int max_value = 1;
			for(int& d : e[root]){
				int current_max = get(1, 1, n, low[d], tail[d]);
				maximize(ans, 1LL * max_value * current_max);
				maximize(max_value, current_max);
			}
		}
		cout << ans << "\n";
	}
}