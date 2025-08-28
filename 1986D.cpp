#include<bits/stdc++.h>
#define taskname "1986D"
using namespace std;
const int INF = 1e4;
template<class T>void minimize(T& a, T b){
	if(a > b){
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
		int n, ans = INF;
		string s;
		cin >> n >> s;
		for(int i = 0; i + 1 < n; i++){
			vector<int>a(1, -1), dp(n, INF);
			for(int j = 0; j < i; j++){
				a.emplace_back(s[j] - 48);
			}
			a.emplace_back((s[i] - 48) * 10 + s[i + 1] - 48);
			for(int j = i + 2; j < n; j++){
				a.emplace_back(s[j] - 48);
			}
			dp[0] = 0;
			for(int j = 1; j < n; j++){
				int value = 1;
				for(int k = j; k > 0; k--){
					minimize(dp[j], dp[k - 1] + (value = min(value * a[k], INF)));
				}
			}
			minimize(ans, dp.back());
		}
		cout << ans << "\n";
	}
}