#include<bits/stdc++.h>
#define taskname "2019A"
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
		int x = *max_element(a.begin(), a.end());
		vector<bool>cnt(2, false);
		for(int i = 0; i < n; i++){
			if(a[i] == x){
				cnt[i & 1] = true;
			}
		}
		cout << (cnt[0] ? x + ((n + 1) >> 1) : x + (n >> 1)) << "\n";
	}
}