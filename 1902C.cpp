#include<bits/stdc++.h>
#define taskname "1902C"
using namespace std;
typedef long long ll;
const int lim = 2e5 + 5;
int a[lim];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, g = 0;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		if(n == 1){
			cout << "1\n";
			continue;
		}
		sort(a + 1, a + n + 1);
		ll ans = 0;
		for(int i = 1; i < n; i++){
			ans += a[n] - a[i];
			g = __gcd(g, a[i + 1] - a[i]);
		}
		bool need = true;
		for(int i = n; i > 0; i--){
			if(a[i] - a[i - 1] > g){
				ans += ll(a[n] - a[i]) + ll(g);
				need = false;
				break;
			}
		}
		if(need){
			ans += ll(a[n] - a[1]) + ll(g);
		}
		cout << ans / ll(g) << "\n";
	}
}