#include<bits/stdc++.h>
#define taskname "895C"
using namespace std;
const int LIM = 71;
const int mod = 1e9 + 7;
const int prime[19] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
void add(int& a, int b){
	if((a += b) >= mod){
		a -= mod;
	}
}
int n, mask[LIM], cnt[LIM];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	mask[0] = mask[1] = 0;
	for(int i = 2; i < LIM; i++){
		for(int j = 0; j < 19; j++){
			if(i % prime[j] == 0){
				mask[i] = mask[i / prime[j]] ^ (1 << j);
				break;
			}
		} 
	}
	cin >> n;
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		cnt[x] = (cnt[x] == 0 ? 1 : (cnt[x] << 1) % mod);
	}
	vector<int>dp(1 << 19, 0), new_dp(1 << 19);
	dp[0] = 1;
	for(int i = 1; i < LIM; i++){
		if(cnt[i] > 0){
			fill(new_dp.begin(), new_dp.end(), 0);
			for(int j = (1 << 19) - 1; j > -1; j--){
				add(new_dp[j], 1LL * dp[j] * cnt[i] % mod);
				add(new_dp[j ^ mask[i]], 1LL * dp[j] * cnt[i] % mod);
			}
			swap(dp, new_dp);
		}
	}
	cout << (dp[0] + mod - 1) % mod;
}