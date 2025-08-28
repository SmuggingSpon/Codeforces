#include<bits/stdc++.h>
#define taskname "579D"
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
	int n, k, x;
	cin >> n >> k >> x;
	vector<int>a(n + 1), pref(n + 1), suf(n + 2);
	pref[0] = suf[n + 1] = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		pref[i] = pref[i - 1] | a[i];
	}
	for(int i = n; i > 0; i--){
		suf[i] = suf[i + 1] | a[i];
	}
	int mul = pow(x, k);
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		maximize(ans, (1LL * a[i] * mul) | pref[i - 1] | suf[i + 1]);
	}
	cout << ans;
}