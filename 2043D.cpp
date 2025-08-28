#include<bits/stdc++.h>
#define taskname "2043D"
using namespace std;
typedef long long ll;
void solve(){
	ll l, r, g;
	cin >> l >> r >> g;
	l = (l - 1) / g + 1;
	r /= g;
	for(ll len = r - l; len > -1; len--){
		for(ll i = l; i + len <= r; i++){
			if(__gcd(i, i + len) == 1){
				return void(cout << i * g << " " << (i + len) * g << "\n");
			}
		}
	}
	cout << "-1 -1\n";
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		solve();
	}
}