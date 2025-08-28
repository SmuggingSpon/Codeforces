#include<bits/stdc++.h>
#define taskname "1920A"
using namespace std;
const int INF = 1e9;
pair<int, int>merge(pair<int, int>a, pair<int, int>b){
	if(a.second < b.first || a.first > b.second){
		return make_pair(-1, -2);
	}
	return make_pair(max(a.first, b.first), min(a.second, b.second));
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		pair<int, int>ans = make_pair(1, INF);
		int n;
		cin >> n;
		map<int, bool>cnt;
		for(int i = 0; i < n; i++){
			int a, x;
			cin >> a >> x;
			if(a == 1){
				ans = merge(ans, make_pair(x, INF));
			}
			else if(a == 2){
				ans = merge(ans, make_pair(1, x));
			}
			else{
				cnt[x] = true;
			}
		}
		int res = ans.second - ans.first + 1;
		for(auto& [x, y] : cnt){
			if(ans.first <= x && ans.second >= x){
				res--;
			}
		}
		cout << res << "\n";
	}
}