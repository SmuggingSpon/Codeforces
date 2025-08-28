#include<bits/stdc++.h>
#define taskname "1979D"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, k;
		string s;
		cin >> n >> k >> s;
		for(char& c : s){
			c -= 48;
		}
		s = '#' + s;
		vector<vector<int>>to(n + 1, vector<int>(2, n + 1));
		for(int i = n - 1; i > 0; i--){
			to[i][s[i + 1]] = i + 1;
			to[i][s[i + 1] ^ 1] = to[i + 1][s[i + 1] ^ 1];
		}
		vector<int>r(n + 2, 0), left_same(n + 1);
		for(int i = n; i > 0; i--){
			if(to[i][s[i] ^ 1] - i == k){
				r[i] = r[i + k] + k;
			}
		}
		left_same[1] = 1;
		for(int i = 2; i <= n; i++){
			left_same[i] = (s[i] == s[i - 1] ? left_same[i - 1] : i);
		}
		if(r[1] == n){
			cout << n << "\n";
			continue;
		}
		int ans = -1;
		for(int i = 1; i < n; i++){
			int index = i + 1 + r[i + 1];
			if(index == n + 1){
				if(r[1] + 1 >= left_same[i] && s[i] != s[n] && i - left_same[i] + 1 == k){
					ans = i;
					break;
				}
			}
			else if(n - index + 1 < k && to[index][s[index] ^ 1] == n + 1 && i - left_same[i] + 2 == k - n + index && s[i] == s[index] && r[1] + 1 >= left_same[i]){
				ans = i;
				break;
			}
		}
		cout << ans << "\n";
	}
}