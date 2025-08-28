#include<bits/stdc++.h>
#define taskname "2066D1"
using namespace std;
const int mod = 1e9 + 7;
const int lim = 305;
void add(int& a, int b){
	if((a += b) >= mod){
		a -= mod;
	}
}
int Ckn[lim][lim];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	memset(Ckn, 0, sizeof(Ckn));
	Ckn[0][0] = 1;
	for(int i = 1; i < lim; i++){
		for(int j = Ckn[0][i] = 1; j < lim; j++){
			Ckn[j][i] = (Ckn[j][i - 1] + Ckn[j - 1][i - 1]) % mod;
		}
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, c, m;
		cin >> n >> c >> m;
		for(int i = 0, foo; i < m; i++){
			cin >> foo;
		}
		vector<int>dp(m + 1, 0);
		dp[c] = 1;
		for(int _ = n - 1; _ > 0; _--){
			for(int i = m; i >= c; i--){
				for(int cnt = 1; cnt <= c; cnt++){
					add(dp[i], 1LL * dp[i - cnt] * Ckn[cnt][c] % mod);
				}
			}
		}
		cout << dp[m] << "\n";
	}
}