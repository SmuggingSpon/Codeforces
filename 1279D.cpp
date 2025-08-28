#include<bits/stdc++.h>
#define taskname "1279D"
using namespace std;
const int mod = 998244353;
const int lim = 1e6 + 5;
void add(int& a, int b){
	if((a += b) >= mod){
		a -= mod;
	}
}
int power(int a, int b){
	int ans = 1;
	for(; b > 0; b >>= 1, a = 1LL * a * a % mod){
		if(b & 1){
			ans = 1LL * ans * a % mod;
		}
	}
	return ans;
}
int n, ans = 0, cnt[lim];
vector<int>item[lim];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n;
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i < n; i++){
		int k;
		cin >> k;
		item[i].resize(k);
		for(int& x : item[i]){
			cin >> x;
			cnt[x]++;
		}
	}
	for(int i = 0; i < n; i++){
		for(int& x : item[i]){
			add(ans, 1LL * cnt[x] * power(1LL * item[i].size() * n % mod * n % mod, mod - 2) % mod);
		}
	}
	cout << ans;
}