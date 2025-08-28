#include<bits/stdc++.h>
#define int long long
#define taskname "1916D"
using namespace std;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n;
		cin >> n;
		if(n == 1){
			cout << "1\n";
		}
		else if(n == 3){
			cout << "169\n196\n961\n";
		}
		else{
			cout << "196" << string(n - 3, '0') << "\n";
			int L = 1, R = 2;
			for(int i = n >> 1; i > 0; i--, L++, R += 2){
				cout << 1;
				for(int j = 1; j < n; j++){
					if(j == L){
						cout << 6;
					}
					else if(j == R){
						cout << 9;
					}
					else{
						cout << 0;
					}
				}
				cout << "\n";
			}
			L = 1;
			R = 2;
			for(int i = n >> 1; i > 0; i--, L++, R += 2){
				cout << 9;
				for(int j = 1; j < n; j++){
					if(j == L){
						cout << 6;
					}
					else if(j == R){
						cout << 1;
					}
					else{
						cout << 0;
					}
				}
				cout << "\n";
			}
		}
	}
}