#include<bits/stdc++.h>
#define taskname "1968D"
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
		int n, k, pb, ps;
		cin >> n >> k >> pb >> ps;
		vector<int>p(n + 1), a(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> p[i];
		}
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		ll B = 0, S = 0, sum = 0;
		for(int i = 0; i < min(k, n); i++, sum += a[pb], pb = p[pb]){
			maximize(B, sum + 1LL * (k - i) * a[pb]);
		}
		for(int i = sum = 0; i < min(k, n); i++, sum += a[ps], ps = p[ps]){
			maximize(S, sum + 1LL * (k - i) * a[ps]);
		}
		cout << (B > S ? "Bodya" : (B < S ? "Sasha" : "Draw")) << "\n";
	}
}