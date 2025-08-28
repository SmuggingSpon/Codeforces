#include<bits/stdc++.h>
#define taskname "2036F"
using namespace std;
typedef long long ll;
ll cnt_remainder_under(ll n, ll d, ll r){
	return n / d * (r + 1) + min(n % d, r) + 1;
}
ll get(ll n){
	ll ans = 0;
	for(int i = 0; i < 60; i++){
		if((n + 1 - cnt_remainder_under(n, 1LL << (i + 1), (1LL << i) - 1)) & 1LL){
			ans |= 1LL << i;
		}
	}
	return ans;
}
ll get(ll n, int k, int i){
	if(k > n){
		return 0;
	}
	return (get((n - k) >> ll(i)) << ll(i)) ^ ((((n - k) >> ll(i)) & 1) ? 0LL : k);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		ll l, r;
		int i, k;
		cin >> l >> r >> i >> k;
		int ans = 0;
		cout << (get(r) ^ get(l - 1) ^ get(r, k, i) ^ get(l - 1, k, i)) << "\n";
	}
}