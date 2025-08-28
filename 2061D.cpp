#include<bits/stdc++.h>
#define taskname "2061D"
using namespace std;
void solve(){
	int n, m;
	cin >> n >> m;
	multiset<int>a, S;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a.insert(x);
	}
	bool ans = true;
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		if(!ans){
			continue;
		}
		S.insert(x);
		while(!S.empty() && S.size() <= a.size()){
			vector<int>add;
			for(auto& x : S){
				auto it = a.find(x);
				if(it != a.end()){
					a.erase(it);
				}
				else if(x == 1){
					ans = false;
				}
				else{
					add.emplace_back(x >> 1);
					add.emplace_back((x + 1) >> 1);
				}
			}
			S.clear();
			for(int& x : add){
				S.insert(x);
			}
		}
		if(!S.empty()){
			ans = false;
		}
	}
	cout << (ans && a.empty() ? "Yes\n" : "No\n");
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		solve();
	}
}