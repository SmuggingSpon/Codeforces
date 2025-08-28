#include<bits/stdc++.h>
#define taskname "1974E"
using namespace std;
typedef long long ll;
const ll INF = 1e18;
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
		int m, x;
		cin >> m >> x;
		vector<int>c(m), h(m);
		for(int i = 0; i < m; i++){
			cin >> c[i] >> h[i];
		}
		int S = accumulate(h.begin(), h.end(), 0);
		vector<ll>dp(S + 1, -INF);
		dp[0] = 0;
		for(int i = 0; i < m; i++){
			for(int j = S; j >= h[i]; j--){
				maximize(dp[j], dp[j - h[i]] - c[i]);
			}
			for(int j = 0; j <= S; j++){
				if(dp[j] > -1){
					dp[j] += x;
				}
			}
		}
		for(int i = S; i > -1; i--){
			if(dp[i] > -1){
				cout << i << "\n";
				break;
			}
		}
	}	
}