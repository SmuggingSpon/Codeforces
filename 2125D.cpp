#include<bits/stdc++.h>
#define taskname "2125D"
using namespace std;
const int lim = 2e5 + 5;
const int mod = 998244353;
int power(int a, int b){
	int ans = 1;
	for(; b > 0; b >>= 1, a = 1LL * a * a % mod){
		if(b & 1){
			ans = 1LL * ans * a % mod;
		}
	}
	return ans;
}
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
	int n, m;
	cin >> n >> m;
	vector<int>l(n), r(n), p(n), q(n), f(m + 2, 0);
	vector<vector<int>>event(m + 1);
	f[m + 1] = 1;
	for(int i = 0; i < n; i++){
		cin >> l[i] >> r[i] >> p[i] >> q[i];
		f[m + 1] = 1LL * f[m + 1] * (q[i] - p[i]) % mod * power(q[i], mod - 2) % mod;
		event[l[i]].emplace_back(i);
	}
	for(int i = m; i > 0; i--){
		for(int& id : event[i]){
			int e1 = 1LL * p[id] * power(q[id], mod - 2) % mod, e2 = power(1LL * (q[id] - p[id]) * power(q[id], mod -  2) % mod, mod - 2);
			add(f[i], 1LL * f[r[id] + 1] * e1 % mod * e2 % mod);
		}
	}
	cout << f[1];
}