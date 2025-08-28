#include<bits/stdc++.h>
#define taskname "2043C"
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
		vector<pair<int, int>>range;
		range.push_back(make_pair(0, 0));
		map<int, int>event;
		for(int _i = 0, sum = 0; _i < n; _i++){
			int x;
			cin >> x;
			sum += x;
			for(int i = 0; i < range.size(); i++){
				event[sum - range[i].second]++;
				event[sum - range[i].first + 1]--;
			}
			bool need = true;
			for(int i = 0; i < range.size() && need; i++){
				if(range[i].first - 1 == sum){
					range[i].first--;
					need = false;
				}
				else if(range[i].second + 1 == sum){
					range[i].second++;
					need = false;
				}
				else if(range[i].first <= sum && range[i].second >= sum){
					need = false;
				}
			}
			if(need){
				range.push_back(make_pair(sum, sum));
			}
		}
		int pre_pos = 0, sum = 0;
		vector<int>ans;
		for(map<int, int>::iterator it = event.begin(); it != event.end(); it++){
			if(sum > 0){
				for(int i = pre_pos; i < it->first; i++){
					ans.push_back(i);
				}
			}
			pre_pos = it->first;
			sum += it->second;
		}
		ans.push_back(0);
		sort(ans.begin(), ans.end());
		ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
		cout << ans.size() << "\n";
		for(int i = 0; i < ans.size(); i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
}