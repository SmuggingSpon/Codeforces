#include<bits/stdc++.h>
#define taskname "2050F"
using namespace std;
const int lim = 2e5 + 5;
int log_v[lim], spt[lim][18];
int get(int l, int r){
	int k = log_v[r - l + 1];
	return __gcd(spt[l][k], spt[r - (1 << k) + 1][k]);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	log_v[0] = -1;
	for(int i = 1; i < lim; i++){
		log_v[i] = log_v[i >> 1] + 1;
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, q;
		cin >> n >> q;
		vector<int>a(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1; i < n; i++){
			spt[i][0] = abs(a[i] - a[i + 1]);
		}
		for(int j = 1; j < 18; j++){
			for(int i = 1; i + (1 << j) - 1 < n; i++){
				spt[i][j] = __gcd(spt[i][j - 1], spt[i + (1 << (j - 1))][j - 1]);
			}
		}
		for(int __ = 0; __ < q; __++){
			int l, r;
			cin >> l >> r;
			cout << (l == r ? 0 : get(l, r - 1)) << " ";
		}
		cout << "\n";
	}
}