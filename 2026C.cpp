#include<bits/stdc++.h>
#define taskname "2026C"
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t; 
	for(int _ = 0; _ < _t; _++){
		int n, cnt = 0;
		string s;
		cin >> n >> s;
		s = '#' + s;
		ll ans = ((1LL * n * (n + 1)) >> 1LL);
		for(int i = n; i > cnt; i--){
			if(s[i] == '0' && cnt > 0){
				cnt--;
			}
			else if(s[i] == '1' && i - 1 > cnt){
				ans -= i;
				cnt++;
			}
		}
		cout << ans << "\n";
	}
}