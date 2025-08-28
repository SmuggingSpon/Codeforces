#include<bits/stdc++.h>
#define taskname "2049C"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, x, y;
		cin >> n >> x >> y;
		if((~n & 1) && ((y - x) & 1)){
			for(int i = 0; i < n; i++){
				cout << (i & 1) << " ";
			}
			cout << "\n";
			continue;
		}
		vector<int>ans(n + 1);
		for(int i = x; i < y; i++){
			ans[i] = (i - x) & 1;
		}
		ans[y] = 2;
		for(int i = (x == 1 ? n : x - 1), parity = 1; i != y; i = (i == 1 ? n : i - 1), parity ^= 1){
			ans[i] = parity;
		}
		for(int i = 1; i <= n; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
}