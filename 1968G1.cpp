#include<bits/stdc++.h>
#define taskname "1968G1"
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
		for(int i = 1, L, R = -1; i < n; i++){
			if(R < i){
				L = R = i;
				while(R < n && s[R] == s[R - i]){
					R++;
				}
				z[i] = R-- - L;
				continue;
			}
			if(R - i + 1 > z[i - L]){
				z[i] = z[i - L];
				continue;
			}
			L = i;
			while(R < n && s[R] == s[R - i]){
				R++;
			}
			z[i] = R-- - L;
		}
		int low = 1, high = n / l, ans = 0;
		while(low <= high){
			int mid = (low + high) >> 1, cnt = 1;
			for(int i = mid; i < n; i++){
				if(z[i] >= mid){
					cnt++;
					i += mid - 1;
				}
			}
			if(cnt >= r){
				low = (ans = mid) + 1;
			}
			else{
				high = mid - 1;
			}
		}
		cout << ans << "\n";
	}
}