#include<bits/stdc++.h>
#define taskname "2125E"
using namespace std;
const int LIM = 2e5 + 5;
const int mod = 998244353;
void add(int& a, int b){
	if((a += b) >= mod){
		a -= mod;
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	vector<vector<int>>f(1, vector<int>(LIM, 0));
	for(int i = f[0][0] = 1; i * (i + 1) - 1 < (LIM << 1); i++){
		f.emplace_back(vector<int>(LIM - ((i * (i + 1)) >> 1)));
		for(int j = f[i][0] = 1; j < min(i, int(f[i].size())); j++){
			f[i][j] = f[i - 1][j];
		}
		for(int j = i; j < f[i].size(); j++){
			f[i][j] = (f[i - 1][j] + f[i][j - i]) % mod;	
		}
	}
	for(int i = 0; i < f.size(); i++){
		for(int j = 1; j < f[i].size(); j++){
			add(f[i][j], f[i][j - 1]);
		}
	}
	for(int _ = 0; _ < _t; _++){
		int n, x;
		cin >> n >> x;
		if(n >= f.size()){
			cout << "0\n";
			continue;
		}
		if(n == 1){
			cout << x << "\n";
			continue;
		}
		int X = x + 1 - ((n * (n + 1)) >> 1), ans = 0;
		n--;
		for(int i = 0; i <= X; i++){
			add(ans, f[n][i]);
		}
		cout << ans << "\n";
	}
}