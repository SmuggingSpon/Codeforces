#include<bits/stdc++.h>
#define taskname "2039B"
using namespace std;
void solve(){
	string s;
	cin >> s;
	for(int i = 1; i < s.size(); i++){
		if(s[i - 1] == s[i]){
			return void(cout << s[i] << s[i] << "\n");
		}
	}
	for(int i = 2; i < s.size(); i++){
		if(s[i - 2] != s[i - 1] && s[i - 2] != s[i] && s[i - 1] != s[i]){
			return void(cout << s[i - 2] << s[i - 1] << s[i] << "\n");
		}
	}
	cout << "-1\n";
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		solve();
	}
}