#include<bits/stdc++.h>
#define taskname "1918D"
using namespace std;
typedef long long ll;
const int lim = 1e5 + 5;
const ll INF = 1e18;
ll st[lim << 2];
int n, a[lim];
void update(int p, ll x){
	int id = 1, l = 1, r = n + 2;
	while(l < r){
		int m = (l + r) >> 1;
		id <<= 1;
		if(m < p){
			l = m + 1;
			id |= 1;
		}
		else{
			r = m;
		}
	}
	st[id] = x;
	while((id >>= 1) > 0){
		st[id] = min(st[id << 1], st[(id << 1) | 1]);
	}
}
ll get(int id, int l, int r, int u, int v){
	if(l > v || r < u){
		return INF;
	}
	if(u <= l && v >= r){
		return st[id];
	}
	int m = (l + r) >> 1;
	return min(get(id << 1, l, m, u, v), get((id << 1) | 1, m + 1, r, u, v));
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
			cin >> a[i];
		}
		ll low = *min_element(a + 1, a + n + 1), high = 1e14, ans;
		while(low <= high){
			ll mid = (low + high) >> 1LL, sum = 0, value = 0;
			fill(st + 1, st + ((n + 2) << 2) + 1, INF);
			update(n + 2, 0);
			update(n + 1, a[n]);
			for(int i = n, r = n; i > 0; i--){
				sum += a[i];
				while(sum > mid){
					sum -= a[r--];
				}
				update(i, (value = get(1, 1, n + 2, i + 1, r + 2)) + a[i - 1]);
			}
			if(value <= mid){
				high = (ans = mid) - 1;
			}
			else{
				low = mid + 1;
			}
		}
		cout << ans << "\n";
	}
}