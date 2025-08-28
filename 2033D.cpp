#include<bits/stdc++.h>
#define taskname "2033D"
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
		vector<int>dp(n + 1, 0);
		map<ll, int>p;
		ll sum = p[0] = 0;
		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;
			dp[i] = dp[i - 1];
			auto it = p.find(sum += x);
			if(it != p.end()){
				maximize(dp[i], dp[it->second] + 1);
			}
			p[sum] = i;
		}
		cout << dp[n] << "\n";
	}
}