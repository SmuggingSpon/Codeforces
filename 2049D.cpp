#include<bits/stdc++.h>
#define taskname "2049D"
using namespace std;
typedef long long ll;
const ll INF = 2e18;
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
		int n, m, k;
		cin >> n >> m >> k;
		vector<ll>dp(n + m, INF), new_dp(n + m), f(3 * m + 1);
		for(int r = dp[0] = f[0] = 0; r < n; r++){
			for(int i = 1; i <= m; i++){
				cin >> f[i];
				f[i + m] = f[i + (m << 1)] = f[i];
			}
			for(int i = 1; i <= 3 * m; i++){
				f[i] += f[i - 1];
			}
			fill(new_dp.begin(), new_dp.end(), INF);
			for(int len = 1; len <= m; len++){
				vector<ll>suf_min((m << 1) + 2);
				suf_min[m << 1 | 1] = INF;
				for(int i = m << 1; i > 0; i--){
					suf_min[i] = min(suf_min[i + 1], 1LL * k * i + f[i + len - 1] - f[i - 1]);
				}
				for(int i = 1; i + len - 1 <= m; i++){
					minimize(new_dp[r + i - 1 + len], dp[r + i - 1] + suf_min[i] - 1LL * k * i);
				}
			}
			swap(dp, new_dp);
		}
		cout << dp[n + m - 1] << "\n";
	}
}