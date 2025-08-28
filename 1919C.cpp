#include<bits/stdc++.h>
#define taskname "1919C"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, a = INT_MAX, b = a, ans = 0;
		cin >> n;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			if(a > b){
				swap(a, b);
			}
			if(x > b){
				a = x;
				ans++;
			}
			else if(x <= a){
				a = x;
			}
			else{
				b = x;
			}
		}
		cout << ans << "\n";
	}
}