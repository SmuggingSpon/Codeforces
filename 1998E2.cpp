#include<bits/stdc++.h>
#define taskname "1998E2"
using namespace std;
typedef long long ll;
const ll LINF = 1e18;
const int lim = 2e5 + 15;
int n, x, bit[lim], st[lim << 2];
void update(int id, int l, int r, int p, int x){
	if(l == r){
		st[id] = x;
		return;
	}
	int m = (l + r) >> 1;
	if(m < p){
		update(id << 1 | 1, m + 1, r, p, x);
	}
	else{
		update(id << 1, l, m, p, x);
	}
	st[id] = max(st[id << 1], st[id << 1 | 1]);
}
int get(int id, int l, int r, int u, int v){
	if(l > v || r < u){
		return 0;
	}
	if(u <= l && v >= r){
		return st[id];
	}
	int m = (l + r) >> 1;
	return max(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
}
void update(int p, int x){
	for(; p <= n; p += p & -p){
		bit[p] += x;
	}
}
int get(int p){
	int ans = 0;
	for(; p > 0; p -= p & -p){
		ans += bit[p];
	}
	return ans;
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
		vector<ll>a(n + 2), f(n + 2);
		a[0] = a[n + 1] = f[0] = LINF;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			f[i] = f[i - 1] + a[i];
		}
		f[n + 1] = f[n] + LINF;
		vector<int>l(n + 2), r(n + 2);
		iota(l.begin(), l.end(), 0);
		iota(r.begin(), r.end(), 0);
		sort(l.begin(), l.end(), [&] (int i, int j) -> bool{
			return f[i] < f[j];
		});	
		sort(r.begin(), r.end(), [&] (int i, int j) -> bool{
			return f[i] - (a[i] << 1LL) < f[j] - (a[j] << 1LL);
		});	
		vector<ll>value = a;
		sort(value.begin(), value.end());
		int r_ptr = 0, current = 0;
		fill(st + 1, st + (n << 2) + 10, 0);
		vector<int>compress_index(n + 2);
		for(int i = 0; i < n + 2; i++){
			compress_index[i] = lower_bound(value.begin(), value.end(), a[i]) - value.begin();
		}
		vector<vector<int>>event(n + 2);
		for(int& L : l){
			while(r_ptr < n + 2 && f[r[r_ptr]] - (a[r[r_ptr]] << 1LL) < f[L]){
				if(r[r_ptr] != n + 1){
					update(1, 0, n + 1, compress_index[r[r_ptr]], r[r_ptr]);
				}
				r_ptr++;
			}
			int r_pos = get(1, 0, n + 1, 0, compress_index[L]);
			if(r_pos > L + 1){
				event[r_pos].emplace_back(L + 1);
			}
		}
		sort(l.begin(), l.end(), [&] (int i, int j) -> bool{
			return f[i] + a[i] < f[j] + a[j];
		});
		sort(r.begin(), r.end(), [&] (int i, int j) -> bool{
			return f[i] - a[i] < f[j] - a[j];
		});
		fill(st + 1, st + (n << 2) + 10, r_ptr = 0);
		for(int& L : l){
			while(r_ptr < n + 2 && f[r[r_ptr]] - a[r[r_ptr]] < f[L] + a[L]){
				update(1, 0, n + 1, compress_index[r[r_ptr]], r[r_ptr]);
				r_ptr++;
			}
			if(L != 0){
				int r_pos = get(1, 0, n + 1, compress_index[L] + 1, n + 1);
				if(r_pos > L + 1){
					event[L].emplace_back(r_pos - 1);
				}
			}
		} 
		set<int>s, sr;
		fill(bit + 1, bit + n + 1, 0);
		vector<int>L(n), R(n);
		iota(L.begin(), L.end(), 1);
		sort(L.begin(), L.end(), [&] (int i, int j) -> bool{
			return a[i] + f[i] > a[j] + f[j];
		});
		vector<int>pref_min(n);
		pref_min[0] = L[0];
		for(int i = 1; i < n; i++){
			pref_min[i] = min(pref_min[i - 1], L[i]);
		}
		for(int i = 1; i <= n; i++){
			s.insert(i);
			update(i, 1);
		}
		for(int i = 1, pl = n - 1, R = 1; i <= n; i++){
			for(int& j : event[i]){
				if(j < i){
					for(auto it = s.lower_bound(j); it != s.end() && *it < i; it = next(it)){
						update(*it, -1);
					}
					s.erase(s.lower_bound(j), s.lower_bound(i));
				}
				else{
					for(auto it = s.upper_bound(i); it != s.end() && *it <= j; it = next(it)){
						update(*it, -1);
					}
					s.erase(s.upper_bound(i), s.upper_bound(j));
				}
			}
			if(a[i] > f[i - 1] - LINF){
				R = i;
			}
			while(pl > -1 && f[i] >= a[L[pl]] + f[L[pl]]){
				pl--;
			}
			cout << get(pl == -1 ? i : min(i, pref_min[pl])) - get(R - 1) << " ";
		}
		cout << "\n";
	}
}