#include<bits/stdc++.h>
#define taskname "453A"
using namespace std;
double power(double a, int b){
	double ans = 1;
	for(; b > 0; b >>= 1, a = a * a){
		if(b & 1){
			ans = ans * a;
		}
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int m, n;
	cin >> m >> n;
	double ans = 0.0, remain = 1.0;
	for(int i = m; i > 0; i--){
		double prob = remain - power(double(i - 1) / double(m), n); 
		ans += double(i) * prob;
		remain -= prob;
	}
	cout << setprecision(9) << fixed << ans;
}