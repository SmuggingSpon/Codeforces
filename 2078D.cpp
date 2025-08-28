#include<bits/stdc++.h>
#define taskname "2078D"
using namespace std;
typedef long long ll;
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
        vector<pair<int, int>>query(n + 1);
        for(int i = 1; i <= n; i++){
            char c1, c2;
            cin >> c1 >> query[i].first >> c2 >> query[i].second;
            if(c1 == 'x'){
                query[i].first = -query[i].first;
            }
            if(c2 == 'x'){
                query[i].second = -query[i].second;
            }
        }
        vector<vector<ll>>dp(n + 2, vector<ll>(2));
        dp[n + 1][0] = dp[n + 1][1] = 1;
        for(int i = n; i > 0; i--){
            dp[i][0] = dp[i + 1][0] + (query[i].first > 0 ? 0 : ll(-query[i].first - 1) * max(dp[i + 1][0], dp[i + 1][1]));
            dp[i][1] = dp[i + 1][1] + (query[i].second > 0 ? 0 : ll(-query[i].second - 1) * max(dp[i + 1][0], dp[i + 1][1]));
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            ans += ll(max(0, query[i].first) + max(0, query[i].second)) * max(dp[i + 1][0], dp[i + 1][1]);
        }
        cout << ans + dp[1][0] + dp[1][1] << "\n";
    }
}