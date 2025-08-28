#include<bits/stdc++.h>
#define taskname "837D"
using namespace std;
typedef long long ll;
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
const int lim = 205;
const int LIM = 5005;
int n, k, dp[lim][LIM];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	memset(dp, -0x0f, sizeof(dp));
	dp[0][0] = 0;
	cin >> n >> k;
	for(int _ = 0; _ < n; _++){
		ll x;
		cin >> x;
		int cnt_2 = 0, cnt_5 = 0;
		while(~x & 1LL){
			x >>= 1LL;
			cnt_2++;
		}
		while(x % 5 == 0){
			x /= 5;
			cnt_5++;
		}
		for(int i = k; i > 0; i--){
			for(int j = cnt_5; j < LIM; j++){
				maximize(dp[i][j], dp[i - 1][j - cnt_5] + cnt_2);
			}
		}
	}
	int ans = 0;
	for(int i = 1; i < LIM; i++){
		maximize(ans, min(i, dp[k][i]));
	}
	cout << ans;
}