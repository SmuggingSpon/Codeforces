#include<bits/stdc++.h>
#define taskname "2094H"
using namespace std;
typedef long long ll;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
const int lim = 1e5 + 5;
vector<int>d[lim], pos[lim];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	for(int i = 1; i < lim; i++){
		for(int j = i; j < lim; j += i){
			d[j].emplace_back(i);
		}
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, q;
		cin >> n >> q;
		vector<int>a(n + 2);
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			pos[a[i]].emplace_back(i);
		}
		a[n + 1] = lim;
		for(int _q = 0; _q < q; _q++){
			int k, l, r;
			cin >> k >> l >> r;
			ll ans = 0;
			while(l <= r){
				int R = r + 1;
				for(int& div : d[k]){
					vector<int>::iterator it = lower_bound(pos[div].begin(), pos[div].end(), l);
					if(it != pos[div].end()){
						minimize(R, *it);
					}
				}
				ans += 1LL * (R - l) * k;
				l = R;
				while(k % a[l] == 0){
					k /= a[l];
				}
			}
			cout << ans << "\n";
		}
		for(int& x : a){
			pos[x].clear();
		}
	}
}