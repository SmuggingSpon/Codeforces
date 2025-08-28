#include<bits/stdc++.h>
#define taskname "2096C"
using namespace std;
typedef long long ll;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
const int lim = 1e3 + 5;
const ll INF = 1e18;
void solve(){
	int n;
	cin >> n;
	vector<vector<int>>h(n + 1, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> h[i][j];
		}
	}
	vector<int>a(n + 1), b(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}
	vector<vector<bool>>state(n + 1, vector<bool>(4, false));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < n; j++){
			if(h[i][j] == h[i][j + 1] - 1){
				state[j][2] = true; 
			}
			else if(h[i][j] == h[i][j + 1]){
				state[j][0] = state[j][3] = true;
			}
			else if(h[i][j] == h[i][j + 1] + 1){
				state[j][1] = true;
			}
		}
	}
	vector<vector<ll>>dp(n + 1, vector<ll>(2, INF));
	ll ans = dp[1][0] = 0;
	dp[1][1] = b[1];
	for(int i = 2; i <= n; i++){
		if(!state[i - 1][0]){
			minimize(dp[i][0], dp[i - 1][0]);
		}
		if(!state[i - 1][1]){
			minimize(dp[i][1], dp[i - 1][0] + b[i]);
		}
		if(!state[i - 1][2]){
			minimize(dp[i][0], dp[i - 1][1]);
		}
		if(!state[i - 1][3]){
			minimize(dp[i][1], dp[i - 1][1] + b[i]);
		}
	}
	ans += min(dp[n][0], dp[n][1]);
	state = vector<vector<bool>>(n + 1, vector<bool>(4, false));
	for(int i = 1; i < n; i++){
		for(int j = 1; j <= n; j++){
			if(h[i][j] == h[i + 1][j] - 1){
				state[i][2] = true;
			}
			else if(h[i][j] == h[i + 1][j]){
				state[i][0] = state[i][3] = true;
			}
			else if(h[i][j] == h[i + 1][j] + 1){
				state[i][1] = true;
			}
		}
	}
	dp = vector<vector<ll>>(n + 1, vector<ll>(2, INF));
	dp[1][0] = 0;
	dp[1][1] = a[1];
	for(int i = 2; i <= n; i++){
		if(!state[i - 1][0]){
			minimize(dp[i][0], dp[i - 1][0]);
		}
		if(!state[i - 1][1]){
			minimize(dp[i][1], dp[i - 1][0] + a[i]);
		}
		if(!state[i - 1][2]){
			minimize(dp[i][0], dp[i - 1][1]);
		}
		if(!state[i - 1][3]){
			minimize(dp[i][1], dp[i - 1][1] + a[i]);
		}
	}
	if((ans += min(dp[n][0], dp[n][1])) >= INF){
		return void(cout << "-1\n");
	}
	cout << ans << "\n";
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		solve();
	}
}