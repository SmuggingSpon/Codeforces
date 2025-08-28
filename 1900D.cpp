#include<bits/stdc++.h>
#define taskname "1900D"
using namespace std;
typedef long long ll;
const int lim = 1e5 + 1;
vector<int>d[lim], p[lim];
ll down[lim];
void solve(){
	
	memset(down, 0, sizeof(down));
	for(int i = 1; i < lim; i++) p[i].clear();
	
	int n;
	cin >> n;
	
	vector<int>a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	
	for(int i = 0; i < n; i++){
		for(int& divisor : d[a[i]]){
			p[divisor].emplace_back(i);
		}
	}
	
	ll ans = 0;
	
	for(int i = lim - 1; i > 0; i--){
		ll add = 0;
		for(int j = 1; j < p[i].size(); j++){
			add += i * ll(n - p[i][j] - 1) * j;
		}
		add -= down[i] * ll(i);
		ans += add;
		for(int& divisor : d[i]){
			down[divisor] += add / ll(i);
		}
	}
	cout << ans << "\n";
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	
	for(int i = 1; i < lim; i++){
		for(int j = i; j < lim; j += i){
			d[j].emplace_back(i);
		}
	}
	
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		solve();
	}
}