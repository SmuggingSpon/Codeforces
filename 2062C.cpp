#include<bits/stdc++.h>
#define taskname "2062C"
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
		vector<ll>a(n);
		for(ll& x : a){
			cin >> x;
		}
		ll ans = accumulate(a.begin(), a.end(), 0LL);
		for(int _ = n; _ > 1; _--){
			vector<ll>A;
			if(a.back() < a[0]){
				reverse(a.begin(), a.end());
			}
			maximize(ans, a.back() - a[0]);
			for(int i = 1; i < a.size(); i++){
				A.emplace_back(a[i] - a[i - 1]);
			}
			a = A;
		}
		cout << ans << "\n";
	}
}