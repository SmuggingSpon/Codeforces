#include<bits/stdc++.h>
#define taskname "1935A"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n;
		string s;
		cin >> n >> s;
		if(n == 0){
			cout << s << "\n";
			continue;
		}
		string S = s;
		reverse(S.begin(), S.end());
		if(n & 1){
			if(S <= s){
				cout << S << "\n";
			}
			else{
				cout << s + S << "\n";
			}
		}
		else{
			if(s <= S){
				cout << s << "\n";
			}
			else{
				cout << S + s << "\n";
			}
		}
	}
}