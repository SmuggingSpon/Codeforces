#include<bits/stdc++.h>
#define taskname "2072F"
using namespace std;
int n, k;
vector<int>solve(int n){
	for(int i = 19; i > -1; i--){
		if((1 << i) <= n){
			if((1 << i) == n){
				return vector<int>(n, k);
			}
			vector<int>ans = solve(n - (1 << i)), temp = ans;
			for(int j = n - (1 << i); j < (1 << i); j++){
				ans.emplace_back(0);
			}			
			for(int& x : temp){
				ans.emplace_back(x);
			}
			return ans;
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
		cin >> n >> k;
		vector<int>ans = solve(n);
		for(int& x : ans){
			cout << x << " ";
		}
		cout << "\n";
	}
}