#include<bits/stdc++.h>
#define taskname "2109B"
using namespace std;
int get(int n, int m){
	int ans = 0;
	while(n > 1){
		n = (n + 1) >> 1;
		ans++;
	}
	while(m > 1){
		m = (m + 1) >> 1;
		ans++;
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		cout << 1 + min(get(min(a, n - a + 1), m), get(n, min(b, m - b + 1))) << "\n";
	}
}