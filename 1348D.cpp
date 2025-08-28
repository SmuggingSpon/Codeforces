#include<bits/stdc++.h>
#define taskname "1348D"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, c = 1;
		cin >> n;
		vector<int>ans;
		n--;
		while(n > 0){
			int C = c << 1;
			if(n - C >= C){
				ans.emplace_back(c);
				n -= (c = C);
			}
			else if(n > C){
				ans.emplace_back((n - C) >> 1);
				n -= (c += ans.back());
			}
			else{
				ans.emplace_back(n - c);
				break;
			}
		}
		cout << ans.size() << "\n";
		for(int& x : ans){
			cout << x << " ";
		}
		cout << "\n";
	}
}