#include<bits/stdc++.h>
#define taskname "1998A"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int xc, yc, k;
		cin >> xc >> yc >> k;
		xc *= k;
		yc *= k;
		for(int i = 1; i < k; i++){
			cout << 1000000 + i << " " << 1000000 + i << "\n";
			xc -= 1000000 + i;
			yc -= 1000000 + i;
		}
		cout << xc << " " << yc << "\n";
	}
}