#include<bits/stdc++.h>
#define taskname "2050E"
using namespace std;
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
		string a, b, c;
		cin >> a >> b >> c;
		vector<vector<int>>dp(int(a.size()) + 1, vector<int>(int(b.size()) + 1, 0));
		for(int i = int(a.size()); i > -1; i--){
			for(int j = int(b.size()); j > -1; j--){
				if(j < b.size()){
					maximize(dp[i][j], dp[i][j + 1] + int(c[i + j] == b[j]));
				}
				if(i < a.size()){
					maximize(dp[i][j], dp[i + 1][j] + int(c[i + j] == a[i]));
				}
			}
		}
		cout << int(c.size()) - dp[0][0] << "\n";
	}
}