#include<bits/stdc++.h>
#define taskname "2102B"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n;
		cin >> n;
		vector<int>a(n);
		for(int& x : a){
			cin >> x;
		}
		int small = 0, large = 0;
		for(int i = 1; i < n; i++){
			if(max(a[i], -a[i]) < a[0]){
				small++;
			}
			else if(min(a[i], -a[i]) > a[0]){
				large++;
			}
		}
		if(small < ((n + 1) >> 1) && large <= (n >> 1)){
			cout << "YES\n";
			continue;
		}
		a[small = large = 0] = -a[0];
		for(int i = 1; i < n; i++){
			if(max(a[i], -a[i]) < a[0]){
				small++;
			}
			else if(min(a[i], -a[i]) > a[0]){
				large++;
			}
		}
		cout << (small < ((n + 1) >> 1) && large <= (n >> 1) ? "YES\n" : "NO\n");
	}
}