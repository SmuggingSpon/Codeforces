#include<bits/stdc++.h>
#define taskname "1766E"
using namespace std;
typedef long long ll;
const int lim = 3e5 + 5;
map<vector<int>, ll>f[lim];
int n, a[lim];
ll dp(int i, vector<int>s){
	if(i == n){
		return 0;
	}
	if(f[i].find(s) != f[i].end()){
		return f[i][s];
	}
	if(a[i] == 0){
		return f[i][s] = n - i + dp(i + 1, s);  
	}
	vector<int>S = s;
	bool need = true;
	for(int j = 0; j < s.size(); j++){
		if((s[j] & a[i]) > 0){
			s[j] = a[i];
			need = false;
			break;
		}
	}
	if(need){
		s.emplace_back(a[i]);
	}
	return f[i][S] = (need ? n - i : 0) + dp(i + 1, s);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ans += dp(i, vector<int>{});
	}
	cout << ans;
}