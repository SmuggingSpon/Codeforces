#include<bits/stdc++.h>
#define taskname "2042D"
using namespace std;
const int lim = 2e5 + 5;
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
		vector<pair<int, int>>line(n);
		for(auto& [l, r] : line){
			cin >> l >> r;
		}
		vector<int>ans(n, -1);
		map<pair<int, int>, int>same_pos;
		for(int i = 0; i < n; i++){
			auto it = same_pos.find(line[i]);
			if(it != same_pos.end()){
				ans[it->second] = ans[i] = 0;
			}
			same_pos[line[i]] = i; 
		}
		vector<int>p(n), R(n);
		iota(p.begin(), p.end(), 0);
		sort(p.begin(), p.end(), [&] (int i, int j) -> bool{
			return line[i].first < line[j].first || (line[i].first == line[j].first && line[i].second > line[j].second);
		});
		set<int>S;
		for(int& i : p){
			if(ans[i] == -1){
				auto it = S.lower_bound(line[i].second);
				if(it != S.end()){
					R[i] = *it;
				}
				else{
					ans[i] = 0;
				}
			}
			S.insert(line[i].second);
		}
		sort(p.begin(), p.end(), [&] (int i, int j) -> bool{
			return line[i].second > line[j].second || (line[i].second == line[j].second && line[i].first < line[j].first);
		});
		S.clear();
		for(int& i : p){
			if(ans[i] == -1){
				auto it = S.upper_bound(line[i].first);
				if(it != S.begin()){
					ans[i] = R[i] - line[i].second + line[i].first - *prev(it);
				}
				else{
					ans[i] = 0;
				}
			}
			S.insert(line[i].first);
		}
		for(int& x : ans){
			cout << x << "\n";
		}
	}
}