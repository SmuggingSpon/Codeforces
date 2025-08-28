#include<bits/stdc++.h>
#define taskname "1670F"
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int lim = 1e3 + 5;
void add(int& a, int b){
	if((a += b) >= mod){
		a -= mod;
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
int n, C[lim], gt[lim];
ll l, r, z;
map<ll, int>f[62];
int Ckn(int k, int n){
	return 1LL * gt[n] * power(1LL * gt[k] * gt[n - k] % mod, mod - 2) % mod;
}
ll dp(int bit, ll sum){
	if(sum == 0 && (1LL << bit) > z){
		return 1;
	}
	auto it = f[bit].find(sum);
	if(it != f[bit].end()){
		return it->second;
	}
	int ans = 0;
	for(int i = int((1LL << bit & z) > 0); i <= min(ll(n), sum); i += 2){
		add(ans, 1LL * C[i] * dp(bit + 1, (sum - i) >> 1LL) % mod);
	}
	return f[bit][sum] = ans;
}
int solve(ll _n){
	for(int i = 0; i < 62; i++){
		f[i].clear();
	}
	return dp(0, _n);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	for(int i = gt[0] = 1; i < lim; i++){
		gt[i] = 1LL * gt[i - 1] * i % mod;
	}
	cin >> n >> l >> r >> z;
	for(int i = 0; i <= n; i++){
		C[i] = Ckn(i, n);
	}
	cout << (solve(r) - solve(l - 1) + mod) % mod;
}