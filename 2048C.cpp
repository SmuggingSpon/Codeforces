#include<bits/stdc++.h>
#define taskname "2048C"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		string s;
		cin >> s;
		int n = s.size();
		vector<pair<int, int>>candidate;
		for(int i = 0; i < n; i++){
			for(int j = i; j > -1; j--){
				if((candidate.empty() || i - j >= candidate[0].second - candidate[0].first) && s[j] != s[n - i + j - 1]){
					if(!candidate.empty() && i - j > candidate[0].second - candidate[0].first){
						candidate.clear();
					}
					candidate.emplace_back(j, i);
				}
			}
		}
		if(candidate.empty()){
			cout << "1 " << n << " 1 1\n";
			continue;
		}
		pair<int, int>ans = candidate.back();
		candidate.pop_back();
		for(auto& [l, r] : candidate){
			bool is_larger = false;
			for(int i = 0; i <= r - l; i++){
				if(s[l + i] != s[ans.first + i]){
					if(s[l + i] != s[n + i - r + l - 1]){
						is_larger = true;
					}
					break;
				}
			}
			if(is_larger){
				ans = make_pair(l, r);
			}
		}
		cout << "1 " << n << " " << ans.first + 1 << " " << ans.second + 1 << "\n";
	}
}