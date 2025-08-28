#include<bits/stdc++.h>
#define taskname "2028B"
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t; 
	for(int _ = 0; _ < _t; _++){
		ll n, b, c;
		cin >> n >> b >> c;
		if(b == 0){
			cout << (c > n - 3 ? n - ll(c < n) : -1) << "\n";
		}
		else{
			cout << (c >= n ? n : n - (n - 1 - c) / b - 1) << "\n";
		}
	}
}