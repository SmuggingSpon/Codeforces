#include<bits/stdc++.h>
#define taskname "1928A"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int a, b;
		cin >> a >> b;
		if(a & 1){
			swap(a, b);
		}
		cout << ((a & 1) || ((b & 1) && (b << 1) == a) ? "No\n" : "Yes\n");
	}
}