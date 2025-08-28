#include<bits/stdc++.h>
#define taskname "2028C"
using namespace std;
typedef long long ll;
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
		int n, m, v;
		cin >> n >> m >> v;
		vector<int>a(n), p(n);
		for(int& x : a){
			cin >> x;
		}
		ll sum = 0;
		for(int l = 0, r = 0; r < n; r++){
			sum += a[r];
			while(l < r && sum - a[l] >= v){
				sum -= a[l++];
			}
			p[r] = (sum >= v ? l : -1);
		}
		vector<int>dp(n);
		for(int i = 0; i < n; i++){
			dp[i] = (p[i] == -1 ? 0 : (p[i] == 0 ? 1 : dp[p[i] - 1] + 1));
		}
		if(dp[n - 1] < m){
			cout << "-1\n";
			continue;
		}
		ll ans = 0;
		vector<ll>f(n);
		f[0] = a[0];
		for(int i = 1; i < n; i++){
			f[i] = f[i - 1] + a[i];
		}
		for(int r = n - 1, l = n - 1, cnt = 0; r > -1; r = p[r] - 1, cnt++){
			while(l > -1 && (l == 0 ? 0 : dp[l - 1]) >= m - cnt){
				l--;
			}
			maximize(ans, f[r] - (l == -1 ? 0 : f[l]));
		}
		cout << ans << "\n";
	}
}