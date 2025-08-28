#include<bits/stdc++.h>
#define taskname "2035E"
using namespace std;
typedef long long ll;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
const ll INF = 1e16;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int x, y, z, k;
		cin >> x >> y >> z >> k;
		ll ans = INF;
		for(int i = 1; i * i <= (z << 1); i++){
			int low = i, high = z, c = i / k, p;
			while(low <= high){
				int mid = (low + high) >> 1;
				if(((1LL * c * (c + 1) * k) >> 1) + 1LL * (mid - c) * i >= z){
					high = (p = mid) - 1;
				}
				else{
					low = mid + 1;
				}
			}
			minimize(ans, 1LL * x * i + 1LL * y * p);
			low = i;
			high = z;
			p = -1;
			while(low <= high){
				int mid = (low + high) >> 1, c = mid / k;
				if(c > i){
					high = mid - 1;
					continue;
				}
				if(((1LL * c * (c + 1) * k) >> 1) + 1LL * (i - c) * mid >= z){
					high = (p = mid) - 1;
				}
				else{
					low = mid + 1;
				}
			}			
			if(p != -1){
				minimize(ans, 1LL * x * p + 1LL * y * i);
			}
		}
		cout << ans << "\n";
	}
}