#include<bits/stdc++.h>
#define taskname "2051G"
using namespace std;
const int INF = 1e9;
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
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int n, q;
	cin >> n >> q;
	vector<int>l(n, 0), r(n, 0);
	vector<vector<int>>d(n, vector<int>(n, 1));
	for(int _q = 0; _q < q; _q++){
		int s;
		char type;
		cin >> s >> type;
		if(type == '+'){
			r[s - 1]++;
		}
		else{
			l[s - 1]++;
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i != j){
					maximize(d[i][j], r[i] - l[j] + 1);
				}
			}
		}
	}
	vector<vector<int>>dp(1 << n, vector<int>(n, INF));
	for(int mask = 1; mask < (1 << n); mask++){
		if(__builtin_popcount(mask) == 1){
			for(int i = 0; i < n; i++){
				if(1 << i & mask){
					dp[mask][i] = 1;
					break;
				}
			}
			continue;
		}
		vector<int>bit;
		for(int i = 0; i < n; i++){
			if(1 << i & mask){
				bit.push_back(i);
			}
		}
		for(int i = 0; i < bit.size(); i++){
			for(int j = 0; j < bit.size(); j++){
				if(i != j){
					minimize(dp[mask][bit[i]], dp[mask ^ (1 << bit[i])][bit[j]] + d[bit[j]][bit[i]]);
				}
			}
		}
	}
	int ans = INF;
	for(int i = 0; i < n; i++){
		minimize(ans, dp[(1 << n) - 1][i] + r[i]);
	}
	cout << ans << "\n";
}