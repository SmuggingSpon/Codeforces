#include<bits/stdc++.h>
#define taskname "2014H"
using namespace std;
typedef long long ll;
const int LIM = 1e6 + 5;
const int lim = 2e5 + 5;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
ll get_random(ll l, ll r){
	return uniform_int_distribution<ll>(l, r)(rng);
}
ll f[lim], value[LIM];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	for(int i = 0; i < LIM; i++){
		value[i] = get_random(1, 1e12);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, q;
		cin >> n >> q;
		f[0] = 0;
		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;
			f[i] = f[i - 1] + value[x];
			value[x] = -value[x];
		}
		for(int _ = 0; _ < q; _++){
			int l, r;
			cin >> l >> r;
			cout << (f[r] - f[l - 1] == 0 ? "YES\n" : "NO\n");
		}
	}
}