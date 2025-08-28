#include<bits/stdc++.h>
#define taskname "2108B"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, x;
		cin >> n >> x;
		if(x == 0){
			if(n == 1){
				cout << "-1\n";
			}
			else if(n & 1){
				cout << n + 3 << "\n";
			}
			else{
				cout << n << "\n";
			}
		}
		else if(n > __builtin_popcount(x)){
			int c = __builtin_popcount(x);
			if((c & 1) == (n & 1)){
				cout << x + n - c << "\n";
			}
			else if(c == 1){
				if(x == 1){
					cout << (x ^ 2) + n << "\n";
				}
				else{
					cout << (x ^ 1) + n - 1 << "\n";
				}
			}
			else{
				cout << x + n - c + 1 << "\n";
			}
		}
		else{
			cout << x << "\n";
		}
	}
}