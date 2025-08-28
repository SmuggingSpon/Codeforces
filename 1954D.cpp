#include<bits/stdc++.h>
#define taskname "1954D"
using namespace std;
const int lim = 5e3 + 1;
const int LIM = 25e6 + 1;
const int mod = 998244353;
int subtract(int a, int b){
	if((a -= b) < 0){
		a += mod;
	}
	return a;
}
void add(int& a, int b){
	if((a += b) >= mod){
		a -= mod;
	}
}
int cnt[lim], gt[LIM], dp[2][lim];
int power(int a, int b){
	int ans = 1; 
	for(; b > 0; b >>= 1, a = 1LL * a * a % mod){
		if(b & 1){
			ans = 1LL * ans * a % mod;
		}
	}
	return ans;
}
int Ckn(int k, int n){
	return k > n ? 0 : 1LL * gt[n] * power(1LL * gt[k] * gt[n - k] % mod, mod - 2) % mod;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	for(int i = gt[0] = 1; i < LIM; i++){
		gt[i] = 1LL * gt[i - 1] * i % mod;
	}
	int n, ans = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> cnt[i];
	}
	sort(cnt, cnt + n);
	bool cur = true, pre = false;
	memset(dp, 0, sizeof(dp));
	const int SUM = 5000 * n;
	for(int max_value = 1, p = 0, S = 0; max_value < 3; max_value++){
		swap(cur, pre);
		while(p < n && cnt[p] <= max_value){
			S += 5000 - cnt[p++];
		}
		for(int sum_value = max_value; sum_value < 5; sum_value++){
			int _S = SUM - S - (n - p) * (5000 - max_value) - sum_value;
			add(ans, 1LL * subtract(dp[cur][sum_value] = _S < 0 ? 0 : Ckn(n - 1, _S + n - 1), dp[pre][sum_value]) * max(max_value, (sum_value + 1) >> 1) % mod);
		}
	}
	cout << ans;
}