#include<bits/stdc++.h>
#define taskname "2024D"
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
const int lim = 4e5 + 5;
const ll INF = 1e18;
ll bit[lim], f[lim];
int n; 
void update(int p, ll x){
	for(; p <= n; p += p & -p){
		minimize(bit[p], x);
	}
}
ll get(int p){
	ll ans = INF;
	for(; p > 0; p -= p & -p){
		minimize(ans, bit[p]);
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = f[0] = 0; _ < _t; _++){
		cin >> n;
		fill(bit + 1, bit + n + 1, INF);
		for(int i = 1; i <= n; i++){
			cin >> f[i];
			f[i] += f[i - 1];
		}
		update(n, 0);
		ll ans = f[1];
		for(int i = 1; i <= n; i++){
			int p;
			cin >> p;
			ll x = get(n - i + 1) + f[i] - f[i - 1];
			maximize(ans, f[p] - x);
			update(n - p + 1, x);
		}
		cout << ans << "\n";
	}
}