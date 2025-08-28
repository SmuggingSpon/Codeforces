#include<bits/stdc++.h>
#define taskname "2051D"
using namespace std;
typedef long long ll;
const int lim = 2e5 + 5;
int n;
ll x, y, sum, a[lim];
ll solve(ll f){
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ll new_sum = sum - a[i];
		if(new_sum <= f){
			ans += n - i - 1;
		}
		else{
			ans += n - max(i, int(lower_bound(a, a + n + 1, new_sum - f) - a - 1)) - 1;
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
		cin >> n >> x >> y;
		for(int i = sum = 0; i < n; i++){
			cin >> a[i];
			sum += a[i];
		}
		sort(a, a + n);
		a[n] = LLONG_MAX;
		cout << solve(y) - solve(x - 1) << "\n";
	}
}
