#include<bits/stdc++.h>
#define taskname "1920C"
using namespace std;
const int lim = 2e5 + 5;
int n, a[lim];
bool check(int d){
	int G = 0;
	for(int i = 1; i <= d; i++){
		int g = 0;
		for(int j = i + d; j <= n; j += d){
			if((g = __gcd(g, abs(a[j] - a[j - d]))) == 1){
				return false;
			}
		}
		G = __gcd(G, g);
	}
	return G != 1;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1; i * i <= n; i++){
			if(n % i == 0){
				ans += (int)check(i);
				if(i * i != n){
					ans += (int)check(n / i);
				}
			}
		}
		cout << ans << "\n";
	}
}