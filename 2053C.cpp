#include<bits/stdc++.h>
#define taskname "2053C"
using namespace std;
typedef long long ll;
int n, k;
pair<ll, ll>solve(int N){
	if(N < k){
		return make_pair(0LL, 0LL);
	}
	pair<ll, ll>ans = solve(N >> 1);
	ans.second = (ans.second << 1LL) + 1LL * (ans.first + (N & 1)) * ((N + 1) >> 1);
	ans.first <<= 1LL;
	if(N & 1){
		ans.first++;
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
	for(int _ = 0; _ < _t; _++){
		cin >> n >> k;
		cout << solve(n).second << "\n";
	}
}