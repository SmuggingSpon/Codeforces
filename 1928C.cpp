#include<bits/stdc++.h>
#define taskname "1928C"
using namespace std;
set<int>ans;
void solve(int n){
	for(int i = 1; i * i <= n; i++){
		if(n % i == 0){
			if(~i & 1){
				ans.insert(1 + (i >> 1));
			}
			int j = n / i;
			if(~j & 1){
				ans.insert(1 + (j >> 1));
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, x, cnt = 0;
		cin >> n >> x;
		ans.clear();
		solve(n - x);
		solve(n + x - 2);
		for(const int& value : ans){
			if(value >= x){
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
}