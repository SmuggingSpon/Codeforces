#include<bits/stdc++.h>
#define taskname "2044E"
using namespace std;
typedef long long ll;
int get(int rx, int ry, int k){
	return min(rx, ry / k);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int k, l1, r1, l2, r2;
		cin >> k >> l1 >> r1 >> l2 >> r2;
		ll ans = 0;
		int temp = k;
		while(true){
			ans += get(r1, r2, temp) - get(l1 - 1, r2, temp) - get(r1, l2 - 1, temp) + get(l1 - 1, l2 - 1, temp);
			if(1LL * temp * k > r2){
				break;
			}
			temp *= k;
		}
		cout << ans + max(0, min(r1, r2) - max(l1, l2) + 1) << "\n";
	}
}