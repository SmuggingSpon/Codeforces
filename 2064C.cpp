#include<bits/stdc++.h>
#define taskname "2064C"
using namespace std;
typedef long long ll;
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n;
		cin >> n;
		vector<int>a(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		vector<ll>f(n + 1);
		f[0] = 0;
		for(int i = 1; i <= n; i++){
			f[i] = f[i - 1] + max(0, a[i]);
		}
		ll ans = f[n], neg = 0;
		for(int i = n; i > 0; i--){
			if(a[i] < 0){
				neg -= a[i];
			}
			maximize(ans, f[i - 1] + neg);
		}
		cout << ans << "\n";
	}
}
