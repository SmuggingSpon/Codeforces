#include<bits/stdc++.h>
#define taskname "1922E"
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		ll x;
		cin >> x;
		int start = 63 - __builtin_clzll(x);
		vector<int>ans;
		if(x & 1LL){
			ans.emplace_back(int(1e9));
		}
		for(int i = 1; i < start; i++){
			if((1LL << ll(i)) & x){
				ans.emplace_back((start << 1) - ((i - 1) << 1) - 1);
			}
		}
		for(int i = 1; i <= start; i++){
			ans.emplace_back(i << 1);
		}
		cout << ans.size() << "\n";
		for(int& x : ans){
			cout << x << " ";
		}
		cout << "\n";
	}
}