#include<bits/stdc++.h>
#define taskname "2036G"
using namespace std;
typedef long long ll;
ll get(ll l, ll r){
	cout << "xor " << l << " " << r << endl;
	ll x;
	cin >> x;
	return x;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		ll n;
		cin >> n;
		ll low = 1, high = n, a, b, c = get(1, n);
		if(c == 0){
			for(int i = 59; i > -1; i--){
				if((1LL << i) > n){
					continue;
				}
				if(get(1LL << i, min((1LL << (i + 1)) - 1, n)) != 0){
					low = 1LL << i;
					high = min((1LL << (i + 1)) - 1, n);
					while(low <= high){
						ll mid = (low + high) >> 1LL;
						if(get(1LL << i, mid) != 0){
							high = (a = mid) - 1;
						}
						else{
							low = mid + 1;
						}
					}
					b = get(1LL << i, min((1LL << (i + 1)) - 1, n)) ^ a;
					break;
				}
			}
		}
		else{
			while(low <= high){
				ll mid = (low + high) >> 1LL;
				if(get(1, mid) != 0){
					high = (a = mid) - 1;
				}
				else{
					low = mid + 1;
				}
			}
			low = a + 1;
			high = n;
			while(low <= high){
				ll mid = (low + high) >> 1LL;
				if(get(a + 1, mid) != 0){
					high = (b = mid) - 1;
				}
				else{
					low = mid + 1;
				}
			}
		}
		cout << "ans " << a << " " << b << " " << (c ^ a ^ b) << endl; 
 	}
}