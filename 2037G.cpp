#include<bits/stdc++.h>
#define taskname "2037G"
using namespace std;
const int LIM = 1e6 + 1;
const int mod = 998244353;
void add(int& a, int b){
	if((a += b) >= mod){
		a -= mod;
	}
}
void sub(int& a, int b){
	if((a -= b) < 0){
		a += mod;
	}
}
int mobius[LIM], dp[LIM];
vector<int>d[LIM];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	memset(dp, 0, sizeof(dp));
	mobius[1] = -1;
	for(int i = 2; i < LIM; i++){
		mobius[i] = 1;
	}
	for(int i = 2; i < LIM; i++){
		for(int j = i << 1; j < LIM; j += i){
			mobius[j] -= mobius[i];
		}
		if(mobius[i] != 0){
			for(int j = i; j < LIM; j += i){
				d[j].emplace_back(i);
			}
		}
	}
	int n, x, sum;
	cin >> n >> x;
	for(int& div : d[x]){
		dp[div] = 1;
	}
	for(int _ = 1; _ < n; _++){
		cin >> x;
		sum = 0;
		for(int& div : d[x]){
			if(mobius[div] == 1){
				add(sum, dp[div]);
			}
			else{
				sub(sum, dp[div]);
			}
		}
		for(int& div : d[x]){
			add(dp[div], sum);
		}
	}
	cout << sum;
}