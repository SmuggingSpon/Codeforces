#include<bits/stdc++.h>
#define taskname "2069C"
using namespace std;
const int mod = 998244353;
void add(int& a, int b){
	if((a += b) >= mod){
		a -= mod;
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n;
		cin >> n;
		vector<int>dp(3, 0);
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			x--;
			vector<int>new_dp = dp;
			if(x == 0){
				add(new_dp[0], 1);
			}
			else if(x == 1){
				add(new_dp[1], (dp[0] + dp[1]) % mod);
			}
			else{
				add(new_dp[2], dp[1]);
			}
			swap(dp, new_dp);
		}
		cout << dp[2] << "\n";
	}
}