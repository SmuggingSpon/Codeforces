#include<bits/stdc++.h>
#define taskname "1930D2"
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
		string s;
		cin >> n >> s;
		ll ans = 0;
		vector<ll>dp(n + 3, 0);
		for(int i = n - 1; i > -1; i--){
			ans += (dp[i] = (s[i] == '0' ? dp[i + 1] : dp[i + 3] + n - i));
		}
		cout << ans << "\n";
	}
}