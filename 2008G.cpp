#include<bits/stdc++.h>
#define taskname "2008G"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, k;
		cin >> n >> k;
		vector<int>a(n);
		for(int& x : a){
			cin >> x;
		}
		if(n == 1){
			cout << k - int(k <= a[0]) << "\n";
			continue;
		}
		int g = 0;
		for(int& x : a){
			g = __gcd(g, x);
		}
		k--;
		int cnt = 0;
		while(true){
			int temp = min(n, k / g + 1);
			if(temp == cnt){
				break;
			}
			k += temp - cnt;
			cnt = temp;
		}
		cout << k << "\n";
	}
}