#include<bits/stdc++.h>
#define taskname "2027D2"
using namespace std;
template<class T>bool minimize(T& a, T b){
	if(a > b){
		a = b;
		return true;
	}
	return false;
}
const int INF = 1e9;
const int mod = 1e9 + 7;
void add(int& a, int b){
	if((a += b) >= mod){
		a -= mod;
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
		int n, m;
		cin >> n >> m;
		vector<int>a(n), b(m);
		for(int& x : a){
			cin >> x;
		}
		for(int& x : b){
			cin >> x;
		}
		vector<int>dp(n + 1, INF), cnt(n + 1, 1), f(n + 2);
		dp[n] = f[n + 1] = 0;
		for(int i = m - (f[n] = 1); i > -1; i--){
			int sum = 0;
			for(int j = n - 1, k = n - 1; j > -1; j--){
				sum += a[j];
				while(sum > b[i]){
					sum -= a[k--];
				}
				if(k >= j){
					if(minimize(dp[j], dp[k + 1] + m - i - 1)){
						cnt[j] = 0;
					}
					if(dp[j] == dp[k + 1] + m - i - 1){
						int low = j + 1, high = k, p = k + 1;
						while(low <= high){
							int mid = (low + high) >> 1;
							if(dp[mid] == dp[k + 1]){
								high = (p = mid) - 1;
							}
							else{
								low = mid + 1;
							}
						}
						add(cnt[j], (f[p] - f[k + 2] + mod) % mod);
					}
				}
				f[j] = (f[j + 1] + cnt[j]) % mod;
			}
		}
		if(dp[0] == INF){
			cout << "-1\n";
			continue;
		}
		cout << dp[0] << " " << cnt[0] << "\n";
	}
}