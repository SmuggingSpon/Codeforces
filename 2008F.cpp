#include<bits/stdc++.h>
#define taskname "2008F"
using namespace std;
const int mod = 1e9 + 7;
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
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, P = 0;
		cin >> n;
		for(int i = 0, sum = 0; i < n; i++){
			int x;
			cin >> x;
			add(P, 1LL * x * sum % mod);
			add(sum, x);
		}
		cout << 1LL * P * power(((1LL * n * (n - 1)) >> 1LL) % mod, mod - 2) % mod << "\n";
	}
}