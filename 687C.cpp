#include<bits/stdc++.h>
#define taskname "687C"
using namespace std;
const int LIM = 501;
bitset<LIM>dp[LIM];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	dp[0].set(0);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= k; i++){
		dp[i].reset();
	}
	for(int _i = 0; _i < n; _i++){
		int x;
		cin >> x;
		for(int i = k; i >= x; i--){
			for(int j = 0; j <= k; j++){
				if((j >= x && dp[i - x].test(j - x)) || dp[i - x].test(j)){
					dp[i].set(j);
				}
			}
		}
	}
	cout << dp[k].count() << "\n";
	for(int i = 0; i <= k; i++){
		if(dp[k].test(i)){
			cout << i << " ";
		}
	}
}