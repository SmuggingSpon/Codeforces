#include<bits/stdc++.h>
#define taskname "2050D"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		string s;
		cin >> s;
		for(int i = 0; i < s.size(); i++){
			while(i > 0 && s[i] > s[i - 1] + 1){
				swap(s[i], s[i - 1]);
				s[--i]--;
			}
		}
		cout << s << "\n";
	}
}