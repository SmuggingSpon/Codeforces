#include<bits/stdc++.h>
#define taskname "2094D"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		string p, s;
		cin >> p >> s;
		bool ans = true;
		int i = 0, j = 0;
		while(i < p.size() && j < s.size()){
			if(p[i] != s[j]){
				ans = false;
				break;
			}
			char pattern = p[i];
			int P = 0, S = 0;
			while(i < p.size() && p[i] == pattern){
				i++;
				P++;
			}
			while(j < s.size() && s[j] == pattern){
				j++;
				S++;
			}
			if(S < P || S > (P << 1)){
				ans = false;
				break;
			}
		}
		cout << (ans && i == p.size() && j == s.size() ? "YES\n" : "NO\n");
	}
}