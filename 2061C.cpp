#include<bits/stdc++.h>
#define taskname "2061C"
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
		vector<vector<int>>dp(n + 1, vector<int>(2, 0));
		vector<int>a(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			if(i > 1){
				dp[i][0] = dp[i - 1][1];
				if(a[i - 2] == a[i] - 1){
					add(dp[i][1], dp[i - 1][0]);
				}
				if(a[i - 1] == a[i]){
					add(dp[i][1], dp[i - 1][1]);
				} 
			}
			else{
				dp[i][dp[i][0] = 1] = int(a[i] == 0);
			}
		}
		cout << (dp[n][0] + dp[n][1]) % mod << "\n";
	}
}