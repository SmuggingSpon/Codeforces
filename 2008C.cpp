#include<bits/stdc++.h>
#define taskname "2008C"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int l, r;
		cin >> l >> r;
		int n = r - l, low = 1, high = 44721, ans;
		while(low <= high){
			int mid = (low + high) >> 1;
			if(((1LL * mid * (mid - 1)) >> 1LL) <= n){
				low = (ans = mid) + 1;
			}
			else{
				high = mid - 1;
			}
		}
		cout << ans << "\n";
	}
}