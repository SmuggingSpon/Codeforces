#include<bits/stdc++.h>
#define taskname "1606E"
using namespace std;
const int lim = 505;
const int mod = 998244353;
void add(int& a, int b){
	if((a += b) >= mod){
		a -= mod;
	}
}
int n, x, pw[lim][lim], dp[lim][lim], Cnk[lim][lim];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	for(int i = 1; i < lim; i++){
		pw[i][0] = 1;
		for(int j = 1; j < lim; j++){
			pw[i][j] = 1LL * pw[i][j - 1] * i % mod;
		}
	}
	memset(Cnk, 0, sizeof(Cnk));
	for(int i = Cnk[0][0] = 1; i < lim; i++){
		Cnk[i][0] = 1;
		for(int j = 1; j <= i; j++){
			Cnk[i][j] = (Cnk[i - 1][j] + Cnk[i - 1][j - 1]) % mod;
		}
	}
	cin >> n >> x;
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= x; i++){
		dp[1][i] = i;
	}
	int cnt = 0;
	for(int i = 2; i <= n; i++){
		for(int j = i; j <= x; j++){
			for(int k = i - 1; k > 0; k--){
				for(int t = 1; t + i - 1 <= j; t += i - 1){
					add(dp[i][j], 1LL * dp[k][j - t - i + 2] * pw[i - 1][i - k] % mod * Cnk[i][i - k] % mod);
				}
			}
		}
	}
	cout << (pw[x][n] - dp[n][x] + mod) % mod;
}