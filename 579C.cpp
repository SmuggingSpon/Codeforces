#include<bits/stdc++.h>
#define taskname "579C"
using namespace std;
int a, b;
double solve_1(){
	int d = a - b; 
	if(d < 0 || (d >> 1) < b){
		return 2e18;
	}
	int low = 1, high = 1e9, k;
	while(low <= high){
		int mid = (low + high) >> 1;
		if(d / (mid << 1) >= b){
			low = (k = mid) + 1;
		}
		else{
			high = mid - 1;
		}
	}
	return double(d) / double(k << 1);
}
double solve_2(){
	int s = a + b; 
	if((s >> 1) < b){
		return 2e18;
	}
	int low = 1, high = 1e9, k;
	while(low <= high){
		int mid = (low + high) >> 1;
		if(s / (mid << 1) >= b){
			low = (k = mid) + 1;
		}
		else{
			high = mid - 1;
		}
	}
	return double(s) / double(k << 1);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> a >> b;
	double ans = min(solve_1(), solve_2());
	if(ans > 1e18){
		return cout << -1, 0;
	}
	cout << setprecision(12) << fixed << ans;
}