#include<bits/stdc++.h>
#define taskname "2026B"
using namespace std;
typedef long long ll;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
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
		vector<ll>a(n);
		for(ll& x : a){
			cin >> x;
		}
		ll ans = LLONG_MAX;
		if(n & 1){
			for(int i = 0; i < n; i += 2){
				if(i == 0 || i == n - 1 || max(a[i] - a[i - 1], a[i + 1] - a[i]) > 1){
					ll current = 1;
					for(int j = i - 1; j > 0; j -= 2){
						maximize(current, a[j] - a[j - 1]);
					}
					for(int j = i + 2; j < n; j += 2){
						maximize(current, a[j] - a[j - 1]);
					}
					minimize(ans, current);
				}
			}
		}
		else{
			ans = 0;
			for(int i = 1; i < n; i += 2){
				maximize(ans, a[i] - a[i - 1]);
			}
		}
		cout << ans << "\n";
	}
}