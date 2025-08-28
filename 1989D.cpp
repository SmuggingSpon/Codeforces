#include<bits/stdc++.h>
#define taskname "1989D"
using namespace std;
typedef long long ll;
template<class T>bool minimize(T& a, T b){
	if(a > b){
		a = b;
		return true;
	}
	return false;
}
const int lim = 1e6 + 5;
int n, m, a[lim], b[lim], cnt[lim], dp[lim];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	memset(cnt, 0x3f, sizeof(cnt));
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
		minimize(cnt[a[i] - b[i]], a[i]);
	}
	int current = cnt[0];
	vector<pair<int, int>>value;
	for(int i = 1; i < lim; i++){
		if(minimize(current, cnt[i])){
			value.emplace_back(current, i);
		}
	}
	reverse(value.begin(), value.end());
	memset(dp, 0, sizeof(dp));
	for(int i = 1, p = 0; i < lim; i++){
		while(p < value.size() && value[p].first <= i){
			p++;
		}
		if(p > 0){
			int cnt = (i - value[p - 1].first) / value[p - 1].second + 1;
			dp[i] = dp[i - value[p - 1].second * cnt] + cnt;
		}
	}
	ll ans = 0;
	for(int i = 1; i <= m; i++){
		int x;
		cin >> x;
		if(x > value.back().first){
			int cnt = (x - value.back().first) / value.back().second + 1;
			x -= value.back().second * cnt;
			ans += cnt;
		}
		ans += dp[x];
	}
	cout << (ans << 1LL);
}