#include<bits/stdc++.h>
#define taskname "2060F"
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int lim = 1e5 + 5;
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
int lpf[lim], inv[20];
vector<int>prime;
int power(int a, int b){
	int ans = 1;
	for(; b > 0; b >>= 1, a = 1LL * a * a % mod){
		if(b & 1){
			ans = 1LL * ans * a % mod;
		}
	}
	return ans;
}
int Ckn(int k, ll n){
	if(k > n){
		return 0;
	}
	int ans = 1;
	for(int i = 0; i < k; i++){
		ans = 1LL * ans * ((n - i) % mod) % mod;
	}
	for(int i = 2; i <= k; i++){
		ans = 1LL * ans * inv[i] % mod;
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	for(int i = 1; i < 20; i++){
		inv[i] = power(i, mod - 2);
	}
	prime.emplace_back(2);
	memset(lpf, 0, sizeof(lpf));
	for(int i = 2; i < lim; i += 2){
		lpf[i] = 2;
	}
	for(int i = 3; i < lim; i += 2){
		if(lpf[i] == 0){
			prime.emplace_back(lpf[i] = i);
		}
		for(int& j : prime){
			int T = i * j;
			if(T >= lim || (lpf[T] = j) == lpf[i]){
				break;
			}
		}
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int k;
		ll n;
		cin >> k >> n;
		cout << n % mod << " ";
		for(int i = 2; i <= k; i++){
			vector<int>ways(17, 1);
			int x = i, ans = 0;
			while(x > 1){
				int p = lpf[x], cnt = 1;
				x /= p;
				while(lpf[x] == p){
					x /= p;
					cnt++;
				}
				for(int j = 1; j < 17; j++){
					ways[j] = 1LL * ways[j] * Ckn(j - 1, cnt + j - 1) % mod;
				}
			}
			for(int j = 1; j < 17; j++){
				for(int t = 1; t < j; t++){
					sub(ways[j], 1LL * ways[t] * Ckn(t, j) % mod);
				}
				add(ans, 1LL * ways[j] * Ckn(j + 1, n + 1) % mod);
			}
			cout << ans << " ";
		}
		cout << "\n";
	}
}