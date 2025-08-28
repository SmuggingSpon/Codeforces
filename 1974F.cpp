#include<bits/stdc++.h>
#define taskname "1974F"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int u = 1, d, l = 1, r, n, m;
		cin >> d >> r >> n >> m;
		map<pair<int, int>, bool>chip;
		set<pair<int, int>>row, col;
		for(int _i = 0; _i < n; _i++){
			int x, y;
			cin >> x >> y;
			chip[make_pair(x, y)] = true;
			row.emplace(x, y);
			col.emplace(y, x);
		}
		vector<int>ans(2, 0);
		for(int i = 0; i < m; i++){
			char c;
			int k;
			cin >> c >> k;
			bool parity = i & 1;
			if(c == 'U'){
				u += k;
				for(auto it = row.begin(); it != row.end(); it++){
					if(it->first >= u){
						break;
					}
					if(chip[*it]){
						chip[*it] = false;
						ans[parity]++;
					}
				}
				row.erase(row.begin(), row.lower_bound(make_pair(u, -1)));
			}
			else if(c == 'D'){
				for(auto it = row.upper_bound(make_pair(d -= k, INT_MAX)); it != row.end(); it++){
					if(chip[*it]){
						chip[*it] = false;
						ans[parity]++;
					}
				}
				row.erase(row.upper_bound(make_pair(d, INT_MAX)), row.end());
			}
			else if(c == 'L'){
				l += k;
				for(auto it = col.begin(); it != col.end(); it++){
					if(it->first >= l){
						break;
					}
					if(chip[make_pair(it->second, it->first)]){
						chip[make_pair(it->second, it->first)] = false;
						ans[parity]++;
					}
				}
				col.erase(col.begin(), col.lower_bound(make_pair(l, -1)));
			}
			else{
				for(auto it = col.upper_bound(make_pair(r -= k, INT_MAX)); it != col.end(); it++){
						if(chip[make_pair(it->second, it->first)]){
						chip[make_pair(it->second, it->first)] = false;
						ans[parity]++;
					}
				}
				col.erase(col.upper_bound(make_pair(r, INT_MAX)), col.end());
			}
		}
		cout << ans[0] << " " << ans[1] << "\n";
	}
}