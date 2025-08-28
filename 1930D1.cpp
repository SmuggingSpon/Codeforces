#include<bits/stdc++.h>
#define taskname "1930D1"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, ans = 0;
		string s;
		cin >> n >> s;
		for(int i = 0; i < n; i++){
			int last = -3;
			for(int j = i, cnt = 0; j < n; j++){
				if(s[j] == '1' && j > last + 2){
					cnt++;
					last = j;
				}
				ans += cnt;
			}
		}
		cout << ans << "\n";
	}
}