#include<bits/stdc++.h>
#define taskname "1927E"
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
		for(int i = 0, l = 1, r = n; i < k; i++){
			if(i & 1){
				for(int j = i; j < n; j += k){
					a[j] = l++;
				}
			}
			else{
				for(int j = i; j < n; j += k){
					a[j] = r--;
				}
			}
		}
		for(int& x : a){
			cout << x << " ";
		}
		cout << "\n";
	}
}