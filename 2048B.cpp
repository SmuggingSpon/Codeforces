#include<bits/stdc++.h>
#define taskname "2048B"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, k, cnt = 0;
		cin >> n >> k;
		vector<int>ans(n + 1, -1);
		for(int i = k; i <= n; i += k){
			ans[i] = ++cnt;
		}
		for(int i = 1; i <= n; i++){
			cout << (ans[i] == -1 ? ++cnt : ans[i]) << " ";
		}
		cout << "\n";
	}
}