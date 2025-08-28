#include<bits/stdc++.h>
#define taskname "2035D"
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 1e9;
const int lim = 2e5 + 5;
int power(int a, int b){
	int ans = 1;
	for(; b > 0; b >>= 1, a = 1LL * a * a % mod){
		if(b & 1){
			ans = 1LL * ans * a % mod;
		}
	}
	return ans;
}
pair<ll, int>st[lim << 2];
int a[lim], cnt[lim];
void build(int id, int l, int r){
	if(l == r){
		st[id] = make_pair(0, l);
		return;
	}
	int m = (l + r) >> 1;
	build(id << 1, l, m);
	build(id << 1 | 1, m + 1, r);
	st[id] = max(st[id << 1], st[id << 1 | 1]);
}
void update(int id, int l, int r, int p, ll x){
	if(l == r){
		st[id] = make_pair(x, p);
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
pair<ll, int>get(int id, int l, int r, int u, int v){
	if(l > v || r < u){
		return make_pair(-1, 0);
	}
	if(u <= l && v >= r){
		return st[id];
	}
	int m = (l + r) >> 1;
	return max(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = cnt[0] = 0; _ < _t; _++){
		int n;
		cin >> n;
		build(1, 1, n);
		ll sum = 0;
		vector<int>even_pos;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			cnt[i] = cnt[i - 1];
			while(~a[i] & 1){
				a[i] >>= 1;
				cnt[i]++;
			}		
			if(cnt[i] > cnt[i - 1]){
				even_pos.emplace_back(i);
			}
			update(1, 1, n, i, a[i]);
			ll ans = (sum += a[i]);
			vector<int>need_reset;
			for(int j = int(even_pos.size()) - 1; j > -1; j--){
				pair<ll, int>value = get(1, 1, n, even_pos[j], i);
				if(value.first > INF){
					ans = (ans - value.first % mod + value.first % mod * ll(power(2, cnt[even_pos[j]])) + mod) % mod;
					break;
				}
				else{
					need_reset.emplace_back(value.second);
					update(1, 1, n, value.second, value.first * ll(power(2, cnt[even_pos[j]] - cnt[even_pos[j] - 1])));
					ans = ans - value.first + value.first * ll(power(2, cnt[even_pos[j]] - cnt[even_pos[j] - 1]));
				}
			}
			for(int& j : need_reset){
				update(1, 1, n, j, a[j]);
			}
			cout << ans % mod << " ";
		}
		cout << "\n";
	}
}