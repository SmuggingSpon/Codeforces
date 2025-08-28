#include<bits/stdc++.h>
#define taskname "2096D"
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
		int n, a = 0, b = 0;
		cin >> n;
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			a ^= x;
			b ^= x + y;
		}
		cout << a << " " << b - a << "\n";
	}
}