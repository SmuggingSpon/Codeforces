#include<bits/stdc++.h>
#define taskname "1207F"
using namespace std;
typedef long long ll;
const int SIZE = 700;
const int lim = 5e5 + 1;
int q, a[lim];
vector<ll>f[SIZE];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	memset(a, 0, sizeof(a));
	cin >> q;
	for(int i = 1; i < SIZE; i++){
		f[i].assign(i, 0);
	}
	for(int _ = 0; _ < q; _++){
		int _t, x, y;
		cin >> _t >> x >> y;
		if(_t == 1){
			a[x] += y;
			for(int i = 1; i < SIZE; i++){
				f[i][x % i] += y;
			}
		}
		else if(x < SIZE){
			cout << f[x][y] << "\n";
		}
		else{
			ll ans = 0;
			for(int i = y; i < lim; i += x){
				ans += a[i];
			}
			cout << ans << "\n";
		}
	}
}