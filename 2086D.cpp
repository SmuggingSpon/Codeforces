#include<bits/stdc++.h>
#define taskname "2086D"
using namespace std;
const int lim = 5e5 + 5;
const int mod = 998244353;
void add(int& a, int b){
    if((a += b) >= mod){
        a -= mod;
    }
}
int power(int a, int b){
    int ans = 1;
    for(; b > 0; b >>= 1, a = 1LL * a * a % mod){
        if(b & 1){
            ans = 1LL * ans * a % mod;
        }
    }
    return ans;
}
int gt[lim], inv_gt[lim];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    for(int i = gt[0] = 1; i < lim; i++){
        gt[i] = 1LL * gt[i - 1] * i % mod;
    }
    inv_gt[lim - 1] = power(gt[lim - 1], mod - 2) % mod;
    for(int i = lim - 2; i > -1; i--){
        inv_gt[i] = 1LL * inv_gt[i + 1] * (i + 1) % mod;
    }
    int _t;
    cin >> _t;
    for(int _ = 0; _ < _t; _++){
        int ans = 1, n = 0;
        vector<int>c(26);
        for(int& x : c){
            cin >> x;
            n += x;
            ans = 1LL * ans * inv_gt[x] % mod;
        }
        int even = n >> 1;
        vector<int>dp(even + 1, 0);
        dp[0] = 1;
        for(int& x : c){
            if(x == 0){
                continue;
            }
            for(int i = even; i >= x; i--){
                add(dp[i], dp[i - x]);
            }
        }
        cout << 1LL * gt[even] * gt[n - even] % mod * ans % mod * dp[even] % mod << "\n";
    }
}
