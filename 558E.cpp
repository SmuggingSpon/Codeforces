#include<bits/stdc++.h>
#define taskname "558E"
using namespace std;
int n, q;
string s;
set<pair<int, int>>p[26];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n >> q >> s;
	for(int i = 0; i < n; ){
		int cnt = 0;
		while(i < n && s[i] == s[i - cnt]){
			i++;
			cnt++;
		}
		p[s[i - 1] - 97].emplace(i - cnt, i - 1);
	}
	for(int _ = 0; _ < q; _++){
		int l, r, k;
		cin >> l >> r >> k;
		l--;
		r--;
		vector<int>order(26);
		iota(order.begin(), order.end(), 0);
		if(k == 0){
			reverse(order.begin(), order.end());
		}	
		int N = l;	
		for(int& i : order){
			int cnt = 0;
			auto init = p[i].lower_bound(make_pair(l, -1));
			if(init != p[i].begin() && prev(init)->second >= l){
				init = prev(init);
			}
			for(auto it = init; it != p[i].end() && it->first <= r; it = next(it)){
				cnt += min(it->second, r) - max(it->first, l) + 1;
			}
			if(cnt > 0){
				vector<pair<int, int>>sub, add(1, make_pair(N, N + cnt - 1));
				for(auto it = init; it != p[i].end() && it->first <= r; it = next(it)){
					sub.emplace_back(*it);
					if(it->first < l && it->second >= l){
						add.emplace_back(it->first, l - 1);
					}
					if(it->second > r){
						add.emplace_back(r + 1, it->second);
					}
				}
				for(auto& it : sub){
					p[i].erase(it);
				}
				for(auto& it : add){
					p[i].insert(it);
				}
				N += cnt;
			}
		}
	}
	for(int i = 0; i < 26; i++){
		for(auto& [l, r] : p[i]){
			for(int j = l; j <= r; j++){
				s[j] = char(i + 97);
			}
		}
	}
	cout << s;
}