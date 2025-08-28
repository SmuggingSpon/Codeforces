#include<bits/stdc++.h>
#define taskname "1316E"
using namespace std;
typedef long long ll;
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
const int lim = 1e5 + 5;
int n, k, p, idx[lim], a[lim], s[lim][7];
ll dp[2][1 << 7];
vector<int>bit[1 << 7];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n >> p >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[idx[i] = i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < p; j++){
			cin >> s[i][j];
		}
	}
	for(int mask = (1 << p) - 1; mask > 0; mask--){
		for(int i = 0; i < 7; i++){
			if(1 << i & mask){
				bit[mask].emplace_back(i);
			}
		}
	}
	sort(idx + 1, idx + n + 1, [&] (int i, int j) -> bool{
		return a[i] > a[j];
	});
	memset(dp, -0x0f, sizeof(dp));
	bool cur = true, pre = false;
	dp[cur][0] = 0;
	for(int i = 1; i <= n; i++){
		swap(cur, pre);
		for(int mask = (1 << p) - 1; mask > -1; mask--){
			int P = bit[mask].size() + k;
			dp[cur][mask] = dp[pre][mask];
			for(int& j : bit[mask]){
				maximize(dp[cur][mask], dp[pre][mask ^ (1 << j)] + (P >= i ? a[idx[P]] - a[idx[i]] : 0) + s[idx[i]][j]);
			}
		}
	}
	ll sum = 0;
	for(int i = 1; i <= k; i++){
		sum += a[idx[i]];
	}
	cout << sum + dp[cur][(1 << p) - 1];
}