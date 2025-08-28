#include<bits/stdc++.h>
#define taskname "2039E"
using namespace std;
const int mod = 998244353;
const int lim = 1e6 + 5;
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
int dp[lim];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	dp[0] = dp[1] = dp[2] = dp[3] = 0;
	for(int i = 4, sum_dp = 0, sub_dp = 0; i < lim; add(sum_dp, dp[i]), add(sub_dp, sum_dp), i++){
		dp[i] = (((1LL * (i - 2) * (i - 1)) >> 1LL) - 1) % mod;
		add(dp[i], 1LL * i * sum_dp % mod);
		sub(dp[i], sub_dp);
	}
	for(int i = 4; i < lim; i++){
		add(dp[i], dp[i - 1]);
	}
	for(int _ = 0; _ < _t; _++){
		int n;
		cin >> n;
		cout << (dp[n] + n - 1) % mod << "\n";
	}
}