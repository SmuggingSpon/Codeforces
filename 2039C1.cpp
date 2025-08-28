#include<bits/stdc++.h>
#define taskname "2039C1"
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
		int x, ans = 0;
		ll m;
		cin >> x >> m;
		for(int i = min(m, ll(x) << 3LL); i > 0; i--){
			if(i != x && (x % (x ^ i) == 0 || i % (x ^ i) == 0)){
				ans++;
			}
		}
		cout << ans << "\n";
	}
}