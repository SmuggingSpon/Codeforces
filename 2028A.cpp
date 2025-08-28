#include<bits/stdc++.h>
#define taskname "2028A"
using namespace std;
void solve(){
	int n, a, b, x = 0, y = 0;
	string s;
	cin >> n >> a >> b >> s;
	for(int _ = 0; _ < 20; _++){
		for(char& c : s){
			if(c == 'N'){
				y++;
			}
			else if(c == 'S'){
				y--;
			}
			else if(c == 'E'){
				x++;
			}
			else{
				x--;
			}
			if(x == a && y == b){
				return void(cout << "YES\n");
			}
		}
	}
	cout << "NO\n";
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