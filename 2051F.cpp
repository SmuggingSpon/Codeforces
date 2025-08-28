#include<bits/stdc++.h>
#define taskname "2051F"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, m, q;
		cin >> n >> m >> q;
		vector<pair<int, int>>range;
		range.push_back(make_pair(m, m));
		for(int __ = 0; __ < q; __++){
			int x;
			cin >> x;
			vector<pair<int, int>>new_range;
			for(int i = 0; i < range.size(); i++){
				if(range[i].first > x){
					new_range.push_back(make_pair(range[i].first - 1, range[i].second));
				}
				else if(range[i].second < x){
					new_range.push_back(make_pair(range[i].first, range[i].second + 1));
				}
				else{
					new_range.push_back(make_pair(1, 1));
					new_range.push_back(make_pair(n, n));
					if(x > range[i].first){
						new_range.push_back(make_pair(range[i].first, x));
					}
					if(x < range[i].second){
						new_range.push_back(make_pair(x, range[i].second));
					}
				}
			}
			swap(range, new_range);
			while(true){
				bool is_change = false;
				for(int i = 0; i < range.size() && !is_change; i++){
					for(int j = i + 1; j < range.size() && !is_change; j++){
						int x = range[i].first, y = range[i].second, u = range[j].first, v = range[j].second;
						if(x > u){
							swap(x, u);
							swap(y, v);
						}
						if(y >= u){
							range.erase(range.begin() + j);
							range.erase(range.begin() + i);
							range.push_back(make_pair(x, max(y, v)));
							is_change = true;
						}
					}
				}
				if(!is_change){
					break;
				}
			}
			int ans = 0;
			for(int i = 0; i < range.size(); i++){
				ans += range[i].second - range[i].first + 1;
			}
			cout << ans << " ";
		}
		cout << "\n";
	}
}