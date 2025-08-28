#include<bits/stdc++.h>
#define taskname "1942B"
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
		for(int i = n - 1, mex = n; i > -1; i--){
			if((a[i] = mex - a[i]) < mex){
				mex = a[i];
			}
		}
		for(int& x : a){
			cout << x << " ";
		}
		cout << "\n";
	}
}