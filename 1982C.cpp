#include<bits/stdc++.h>
#define taskname "1982C"
using namespace std;
typedef long long ll;
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
const int lim = 1e5 + 5;
int st[lim << 2];
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
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n;
		ll l, r;
		cin >> n >> l >> r;
		vector<ll>sum(n + 1);
		sum[0] = 0;
		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;
			sum[i] = sum[i - 1] + x;
		}
		vector<int>dp(n + 2, 0);
		fill(st, st + (n << 2) + 5, 0);
		for(int i = n, L = n, R = n; i > 0; i--){
			while(L >= i && sum[L] - sum[i - 1] >= l){
				L--;
			}
			L = min(L + 1, n);
			while(R > i && sum[R] - sum[i - 1] > r){
				R--;
			}
			dp[i] = dp[i + 1];
			if(sum[L] - sum[i - 1] >= l && sum[L] - sum[i - 1] <= r && sum[R] - sum[i - 1] >= l && sum[R] - sum[i - 1] <= r && L <= R){
				maximize(dp[i], get(1, 1, n + 1, L + 1, R + 1) + 1);
			}
			update(1, 1, n + 1, i, dp[i]);
		}
		cout << dp[1] << "\n";
	}
}