#include<bits/stdc++.h>
#define taskname "2027D1"
using namespace std;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
const int INF = 1e9;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, m;
		cin >> n >> m;
		vector<int>a(n), b(m);
		for(int& x : a){
			cin >> x;
		}
		for(int& x : b){
			cin >> x;
		}
		vector<int>dp(n + 1, INF);
		dp[n] = 0;
		for(int i = m - 1; i > -1; i--){
			int sum = 0;
			for(int j = n - 1, k = n - 1; j > -1; j--){
				sum += a[j];
				while(sum > b[i]){
					sum -= a[k--];
				}
				minimize(dp[j], dp[k + 1] + m - i - 1);
			}
		}
		cout << (dp[0] == INF ? -1 : dp[0]) << "\n";
	}
}