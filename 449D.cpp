#include<bits/stdc++.h>
#define taskname "449D"
using namespace std;
const int LIM = 1 << 20;
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
int pw_2[LIM], dp[LIM];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	for(int i = pw_2[0] = 1; i < LIM; i++){
		pw_2[i] = (pw_2[i - 1] << 1) % mod;
	}
	int n;
	cin >> n;
	memset(dp, 0, sizeof(dp));
	for(int _ = 0; _ < n; _++){
		int x;
		cin >> x;
		dp[x]++;
	}
	for(int i = 0; i < 20; i++){
		for(int mask = 0; mask < LIM; mask++){
			if((1 << i & mask) == 0){
				dp[mask] += dp[mask | (1 << i)];
			}
		}
	}
	int ans = 0;
	for(int mask = 0; mask < LIM; mask++){
		if(__builtin_popcount(mask) & 1){
			sub(ans, pw_2[dp[mask]]);
		}
		else{
			add(ans, pw_2[dp[mask]]);
		}
	}
	cout << ans;
}