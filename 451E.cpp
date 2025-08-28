#include<bits/stdc++.h>
#define taskname "451E"
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
void add(int& a, int b){
	if((a += b) >= mod){
		a -= mod;
	}
}
void sub(int& a, int b){
	if((a -= b) < 0){
		a += mod;
	}
}
int power(int a, int b){
	int ans = 1;
	for(; b > 0; b >>= 1, a = 1LL * a * a % mod){
		if(b & 1){
			ans = 1LL * ans * a % mod;
		}
	}
	return ans;
}
int n, inv_gt = 1;
ll s, a[20];
int Ckn(int k, ll n){
	int ans = inv_gt;
	for(ll i = n - k + 1; i <= n; i++){
		ans = ll(ans) * (i % mod) % mod;
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n >> s;
	for(int i = 0; i < n; ){
		cin >> a[i];
		inv_gt = 1LL * inv_gt * ++i % mod;
	}
	inv_gt = 1LL * power(inv_gt, mod - 2) * n % mod;
	int ans = 0;
	for(int mask = (1 << n) - 1; mask > -1; mask--){
		ll sum = s;
		for(int i = 0; i < n; i++){
			if(1 << i & mask){
				sum -= a[i] + 1;
			}
		}
		if(sum > -1){
			if(__builtin_popcount(mask) & 1){
				sub(ans, Ckn(n - 1, sum + n - 1));
			}
			else{
				add(ans, Ckn(n - 1, sum + n - 1));
			}
		}
	}
	cout << ans;
}