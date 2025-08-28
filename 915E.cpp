#include<bits/stdc++.h>
#define taskname "915E"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int n, q;
	cin >> n >> q;
	set<pair<int, int>>range;
	range.emplace(1, n);
	int ans = n;
	for(int _ = 0; _ < q; _++){
		int l, r, k;
		cin >> l >> r >> k;
		vector<pair<int, int>>sub, add;
		auto init = range.lower_bound(make_pair(l, -1));
		if(init != range.begin() && prev(init)->second >= l){
			init = prev(init);
		}
		for(auto it = init; it != range.end() && it->first <= r; it = next(it)){
			sub.emplace_back(*it);
			ans -= it->second - it->first + 1;
			if(it->first < l && it->second >= l){
				add.emplace_back(it->first, l - 1);
				ans += l - it->first;
			}
			if(it->second > r){
				add.emplace_back(r + 1, it->second);
				ans += it->second - r;
			}
		}
		for(auto& it : sub){
			range.erase(it);
		}
		for(auto& it : add){
			range.insert(it);
		}
		if(k == 2){
			range.emplace(l, r);
			ans += r - l + 1;
		}
		cout << ans << "\n";
	}
}