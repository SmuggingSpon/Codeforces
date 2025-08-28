#include<bits/stdc++.h>
#define taskname "2039C2"
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		ll x, m, ans = 0;
		cin >> x >> m;
		if(m <= x){
			ans = 0;
			for(int i = 1; i <= m; i++){
				if((x ^ i) % i == 0 || (x ^ i) % x == 0){
					ans++;
				}
			}
			cout << ans << "\n";
			continue;
		}
		for(int i = 1; i <= min(m, x << 2LL); i++){
			if((x ^ i) % i == 0 && (x ^ i) % x != 0){
				ans++;
			}
		}
		ans += (m - x < x ? 1 : (m - x) / x);
		ll X = x;
		x = 1LL * x * (m / x);
		if((x = 1LL * x * (m / x)) == X){
			x += X;
		}
		while(x <= m + X){
			if((x ^ X) <= m){
				ans++;
			}
			x += X;
		}
		cout << ans << "\n";
	}
}