#include<bits/stdc++.h>
#define taskname "2057C"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int l, r;
		cin >> l >> r;
		vector<int>a(3, 0);
		for(int i = 29; i > -1; i--){
			int bit = 1 << i;
			if(l >= bit){
				l ^= bit;
				r ^= bit;
				for(int& x : a){
					x ^= bit;
				}
			}
			else if(r >= bit){
				a[0] ^= bit;
				a[1] ^= l;
				for(int j = i - 1; j > -1; j--){
					a[2] ^= 1 << j;
				}
				if(a[1] == a[2]){
					a[1] += 2;
				}
				break;
			}
		}
		for(int& x : a){
			cout << x << " ";
		}
		cout << "\n";
	}
}