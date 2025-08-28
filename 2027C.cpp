#include<bits/stdc++.h>
#define taskname "2027C"
using namespace std;
typedef long long ll;
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
const int lim = 3e5 + 5;
map<ll, ll>f;
map<ll, vector<int>>p;
ll dp(ll n){
	if(f.find(n) != f.end()){
		return f[n];
	}
	auto it = p.find(f[n] = n);
	if(it != p.end()){
		for(int& index : it->second){
			maximize(f[n], dp(n + index));
		}
	}
	return f[n];
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
		f.clear();
		p.clear();
		for(int i = 1; i <= n; i++){
			ll x;
			cin >> x;
			if(i > 1){
				p[x + i - 1].emplace_back(i - 1);
			}
		}
		cout << dp(n) << "\n";
	}
}