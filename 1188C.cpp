#include<bits/stdc++.h>
#define taskname "1188C"
using namespace std;
const int lim = 1e3 + 5;
const int LIM = 1e5 + 5;
const int mod = 998244353;
void add(int& a, int b){
    if((a += b) >= mod){
        a -= mod;
    }
}
vector<pair<int, int>>p[LIM];
int n, k, ans = 0, a[lim], dp[lim][lim];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    iota(dp[1] + 1, dp[1] + n + 1, 1);
    for(int i = 2; i <= k; i++){
        dp[i][0] = 0;
    }
    for(int i = LIM / (k - 1), pre = 0; i > 0; pre = dp[k][n], i--){
        for(int j = 2; j <= k; j++){
            for(int r = 1, l = 1; r <= n; r++){
                while(a[r] - a[l] >= i){
                    l++;
                }
                dp[j][r] = (dp[j][r - 1] + dp[j - 1][l - 1]) % mod;
            }
        }
        add(ans, 1LL * (dp[k][n] - pre + mod) * i % mod);
    }
    cout << ans;
}