#include<bits/stdc++.h>
#define taskname "1968G2"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, l, r;
		string s;
		cin >> n >> l >> r >> s;
		vector<int>z(n);
		vector<vector<int>>p(n);
		for(int i = 1, L, R = -1; i < n; p[z[i]].emplace_back(i++)){
			if(R < i){
				L = R = i;
				while(R < n && s[R] == s[R - i]){
					R++;
				}
				z[i] = R-- - i;
				continue;
			}
			if(z[i - L] < R - i + 1){
				z[i] = z[i - L];
				continue;
			}
			L = i;
			while(R < n && s[R] == s[R - i]){
				R++;
			}
			z[i] = R-- - i;
		}
		set<int>S;
		vector<int>cnt(n + 1, 1);
		for(int i = (cnt[0] = n) - 1; i > 0; i--){
			for(int& x : p[i]){
				S.insert(x);
			}
			for(int j = i; ; ){
				auto it = S.lower_bound(j);
				if(it == S.end()){
					break;
				}
				j = *it + i;
				cnt[i]++;
			}
		}
		for(int i = l; i <= r; i++){
			for(int j = n / i; j > -1; j--){
				if(cnt[j] >= i){
					cout << j << " ";
					break;
				}
			}
		}
		cout << "\n";
	}
}