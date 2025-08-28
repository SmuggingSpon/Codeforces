#include<bits/stdc++.h>
#define taskname "1930C"
using namespace std;
const int lim = 3e5 + 5;
const int INF = 2e9;
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
		set<int, greater<int>>ans;
		set<pair<int, int>>range;
		range.emplace(1, INF);
		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;
			x += i;
			auto it = prev(range.lower_bound(make_pair(x + 1, -1)));
			pair<int, int>current = *it;
			range.erase(it);
			if(current.second <= x){
				if(current.first < current.second){
					range.emplace(current.first, current.second - 1);
				}
				ans.insert(current.second);
			}
			else{
				ans.insert(x);
				if(current.first < x){
					range.emplace(current.first, x - 1);
				}
				if(current.second > x){
					range.emplace(x + 1, current.second);
				}
			}
		}
		for(const int value : ans){
			cout << value << " ";
		}
		cout << "\n";
	}
}