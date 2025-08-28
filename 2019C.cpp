#include<bits/stdc++.h>
#define taskname "2019C"
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
		int n;
		ll k;
		cin >> n >> k;
		vector<ll>a(n);
		for(ll& x : a){
			cin >> x;
		}
		sort(a.begin(), a.end(), greater<ll>());
		ll sum = 0;
		for(int i = 1; i < n; i++){
			sum += a[i];
		}
		for(int ans = min(ll(n), (sum + k) / a[0] + 1); ans > 0; ans--){
			if(1LL * ans * ((sum + a[0] - 1) / ans + 1) <= sum + a[0] + k){
				cout << ans << "\n";
				break;
			}
		}
	}
}