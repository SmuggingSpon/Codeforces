#include<bits/stdc++.h>
#define taskname "1935D"
using namespace std;
typedef long long ll;
ll sum(int n){
	ll ans = (1LL * (n + 1) * (n + 2)) >> 1LL;
	ans -= (n >> 1) + 1;
	return (ans >> 1LL) + (n >> 1) + 1;
}
ll f(int n){
	return (1LL * n * (n - 1)) >> 1LL;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, c;
		cin >> n >> c;
		vector<int>s(n), cnt(2, 0);
		for(int& x : s){
			cin >> x;
			cnt[x & 1]++;
		}
		ll ans = sum(c) + sum(c - 1);
		for(int& x : s){
			ans -= ((c << 1) - x + 2) >> 1;
		}
		cout << ans + f(cnt[0]) + f(cnt[1]) << "\n";
	}
}