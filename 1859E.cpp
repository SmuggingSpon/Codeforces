#include<bits/stdc++.h>
#define taskname "1859E"
using namespace std;
typedef long long ll;
const ll INF = 1e18;
template<class T>void maximize(T& a, T b){
    if(a < b){
        a = b;
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
        int n, k;
        cin >> n >> k;
        vector<int>a(n), b(n);
        for(int& x : a){
            cin >> x;
        }
        for(int& x : b){
            cin >> x;
        }
        vector<vector<ll>>dp(n + 1, vector<ll>(5, -INF));
        dp[0][0] = 0;
        for(int i = 0; i < n; i++){
            vector<vector<ll>>ndp(n + 1, vector<ll>(5, -INF));
            for(int j = 0; j <= i; j++){
                ndp[j][0] = dp[j][0]; 
            }
            for(int j = 0; j <= i; j++){
                maximize(ndp[j + 1][0], max({dp[j][0] + (ll(abs(a[i] - b[i])) << 1LL), dp[j][1] - a[i] - b[i], dp[j][2] + a[i] + b[i], dp[j][3] + a[i] - b[i], dp[j][4] - a[i] + b[i]}));
                ndp[j + 1][1] = max(dp[j][1], dp[j][0] + a[i] + b[i]);
                ndp[j + 1][2] = max(dp[j][2], dp[j][0] - a[i] - b[i]);
                ndp[j + 1][3] = max(dp[j][3], dp[j][0] + a[i] - b[i]);
                ndp[j + 1][4] = max(dp[j][4], dp[j][0] - a[i] + b[i]);
            }
            swap(dp, ndp);
        }
        cout << dp[k][0] << "\n";
    }
}