#include<bits/stdc++.h>
#define taskname "2056E"
using namespace std;
const int lim = 4e5 + 5;
const int mod = 998244353;
int gt[lim];
int power(int a, int b){
	int ans = 1;
	for(; b > 0; b >>= 1, a = 1LL * a * a % mod){
		if(b & 1){
			ans = 1LL * ans * a % mod;
		}
	}
	return ans;
}
int Ckn(int k, int n){
	return 1LL * gt[n] * power(1LL * gt[k] * gt[n - k] % mod, mod - 2) % mod;
}
int Catalan(int n){
	return 1LL * Ckn(n, n << 1) * power(n + 1, mod - 2) % mod;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	for(int i = gt[0] = 1; i < lim; i++){
		gt[i] = 1LL * gt[i - 1] * i % mod;
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>event(n + 1);
		vector<pair<int, int>>range;
		auto add_range = [&] (int l, int r){
			event[l].emplace_back(range.size());
			range.emplace_back(l, r);
		};
		add_range(1, n);
		for(int i = 1; i <= n; i++){
			add_range(i, i);
		}
		for(int i = 0; i < m; i++){
			int l, r;
			cin >> l >> r;
			add_range(l, r);
		}
		stack<int>st;
		vector<int>deg(n + m + 1, 0);
		for(int i = 1; i <= n; i++){
			sort(event[i].begin(), event[i].end(), [&] (int x, int y) -> bool{
				return range[x].second > range[y].second;
			});
			for(int& index : event[i]){
				while(!st.empty() && range[st.top()].second < i){
					st.pop();
				}
				if(!st.empty()){
					deg[st.top()]++;
				}
				st.push(index);
			}
		}
		int ans = 1;
		for(int i = n + m; i > -1; i--){
			if(deg[i] > 0){
				ans = 1LL * ans * Catalan(deg[i] - 1) % mod;
			}
		}
		cout << ans << "\n";
	}
}