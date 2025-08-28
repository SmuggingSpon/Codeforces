#include<bits/stdc++.h>
#define taskname "1968F"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, q;
		cin >> n >> q;
		map<int, vector<int>>p;
		vector<int>f(n + 1);
		p[f[0] = 0].emplace_back(0);
		for(int i = 1; i <= n; p[f[i] ^= f[i - 1]].emplace_back(i++)){
			cin >> f[i];
		}
		for(int _i = 0; _i < q; _i++){
			int l, r;
			cin >> l >> r;
			int T = f[r] ^ f[l - 1];
			if(T == 0){
				cout << "YES\n";
			}
			else{
				vector<int>::iterator it = upper_bound(p[f[r]].begin(), p[f[r]].end(), l - 1);
				if(*it < r){
					vector<int>::iterator IT = upper_bound(p[f[l - 1]].begin(), p[f[l - 1]].end(), *it);
					cout << (IT != p[f[l - 1]].end() && *IT < r ? "YES\n" : "NO\n");
				}
				else{
					cout << "NO\n";
				}
			}
		}
		cout << "\n";
	}
}