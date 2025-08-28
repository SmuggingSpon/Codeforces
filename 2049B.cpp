#include<bits/stdc++.h>
#define taskname "2049B"
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
		bool ans = true;
		for(int i = 0; i < n; i++){
			if(s[i] != '.'){
				for(int j = i + 1; j < n; j++){
					if(s[i] == 'p' && s[j] == 's'){
						ans = false;
						break;
					}
					if(s[j] != '.' && s[j] != s[i] && j - i + 1 < min(s[i] == 'p' ? i + 1 : n - i, s[j] == 'p' ? j + 1 : n - j)){
						ans = false;
						break;
					}
				}
				if(!ans){
					break;
				}
			}
		}
		cout << (ans ? "YES\n" : "NO\n");
	}
}