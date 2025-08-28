#include<bits/stdc++.h>
#define taskname "2034B"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, m, k, ans = 0, cnt = 0;
		string s;
		cin >> n >> m >> k >> s;
		s += '1';
		for(int i = 0; i <= n; i++){
			if(s[i] == '1'){
				cnt = 0;
			}
			else if(++cnt == m){
				for(int j = i; j <= min(n, i + k - 1); j++){
					s[j] = '1';
				}
				i += k - 1;
				ans++;
				cnt = 0;
			}
		}
		cout << ans << "\n";
	}
}