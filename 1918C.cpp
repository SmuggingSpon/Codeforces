#include<bits/stdc++.h>
#define taskname "1918C"
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		ll a, b, r, R = 0;
		cin >> a >> b >> r;
		R = r;
		ll S = a ^ b, ans = 0;
		for(int i = 59; i > -1; i--){
			ll bit = 1LL << i;
			if(bit > r){
				if(bit & S){
					if(ans < 0 && (bit & a)){
						ans += bit;
					}
					else if(ans > 0 && (bit & a) == 0){
						ans -= bit;
					}
					else{
						if(bit & a){
							ans += bit;
						}
						else{
							ans -= bit;
						}
					}
				}
			}
			else{
				if(bit & S){
					if(ans < 0){
						ans += bit;
						if((bit & a) == 0){
							r -= bit;
						}
					}
					else{
						ans -= bit;
						if(bit & a){
							r -= bit;
						}
					}
				}
			}
		}
		ll res = abs(ans);
		ans = 0;
		swap(a, b);
		r = R;
		for(int i = 59; i > -1; i--){
			ll bit = 1LL << i;
			if(bit > r){
				if(bit & S){
					if(bit & a){
						ans += bit;
					}
					else{
						ans -= bit;
					}
				}
			}
			else{
				if(bit & S){
					if(ans < 0){
						ans += bit;
						if((bit & a) == 0){
							r -= bit;
						}
					}
					else{
						ans -= bit;
						if(bit & a){
							r -= bit;
						}
					}
				}
			}
		}
		cout << min(abs(ans), res) << "\n";
	}	
}