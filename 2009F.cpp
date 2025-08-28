#include<bits/stdc++.h>
#define taskname "2009F"
using namespace std;
typedef long long ll;
const int lim = 2e5 + 5;
int n, q;
ll a[lim];
ll f(ll N){
	int cnt_block = N / n;
	if((N %= n) == 0){
		return cnt_block * a[n];
	}
	ll ans = 1LL * cnt_block++ * a[n];
	return ans + (n - cnt_block + 1 < N ? a[n] - a[cnt_block - 1] + a[N - n + cnt_block - 1] : a[cnt_block + N - 1] - a[cnt_block - 1]);  
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = a[0] = 0; _ < _t; _++){
		cin >> n >> q;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			a[i] += a[i - 1];
		}
		for(int i = 0; i < q; i++){
			ll l, r;
			cin >> l >> r;
			cout << f(r) - f(l - 1) << "\n";
		}
	}
}