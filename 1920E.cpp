#include<bits/stdc++.h>
#define taskname "1920E"
using namespace std;
const int mod = 998244353;
const int lim = 2505;
void add(int& a, int b){
	if((a += b) >= mod){
		a -= mod;
	}
}
int dp[lim][lim];
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
		vector<vector<int>>d(k + 1), D(k + 1);
		for(int i = 0; i < k; i++){
			for(int j = min(k - i - 1, n / (i + 1)); j > -1; j--){
				d[i + 1].emplace_back(j + 1);
			}
		}
		for(int i = 1; i <= k; i++){
			sort(d[i].begin(), d[i].end());
			for(int& x : d[i]){
				D[i].emplace_back(i * x);
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= k; j++){
				dp[i][j] = 0;
			}
		}
		for(int i = 1; i <= k; i++){
			dp[0][i] = 1;
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= k; j++){
				int N = d[j].size();
				for(int t = 0; t < N; t++){
					if(D[j][t] <= i){
						add(dp[i][j], dp[i - D[j][t]][d[j][t]]);
					}
					else{
						break;
					}
				}
			}
		}
		int ans = 0;
		for(int i = 1; i <= k; i++){
			add(ans, dp[n][i]);
		}
		cout << ans << "\n";
	}
}