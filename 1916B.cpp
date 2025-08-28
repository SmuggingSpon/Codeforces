#include<bits/stdc++.h>
#define taskname "1916B"
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
		ll a, b;
		cin >> a >> b;
		if(b % a == 0){
			cout << b * b / a << "\n";
		}
		else{
			cout << a * b / __gcd(a, b) << "\n";
		}
	}
}