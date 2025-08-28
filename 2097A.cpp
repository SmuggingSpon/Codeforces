#include<bits/stdc++.h>
#define taskname "2097A"
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
		map<int, int>cnt;
		for(int& x : a){
			cin >> x;
			cnt[x]++;
		}	
		bool ans = false;	
		int pre_2 = -1;
		for(auto& [u, v] : cnt){
			if(v > 1){
				if(pre_2 + 1 == u || v > 3){
					ans = true;
					break;
				}
				pre_2 = u;
			}
			else if(u > ++pre_2){
				pre_2 = -1;
			}
		}
		cout << (ans ? "YES\n" : "NO\n");
	}
}