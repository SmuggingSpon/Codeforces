#include<bits/stdc++.h>
#define taskname "2019D"
using namespace std;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
pair<int, int>overlap(pair<int, int>a, pair<int, int>b){
	if(a.first > b.second || b.first > a.second){
		return make_pair(-1, -2);
	}
	return make_pair(max(a.first, b.first), min(a.second, b.second));
}
void solve(){
	int n;
	cin >> n;
	vector<pair<int, int>>range(n + 1, make_pair(n + 1, -1));
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		minimize(range[x].first, i);
		maximize(range[x].second, i);
	}
	pair<int, int>ans = make_pair(1, n), current = make_pair(n + 1, -1);
	for(int i = 1; i <= n; i++){
		minimize(current.first, range[i].first);
		maximize(current.second, range[i].second);
		if(current.second - current.first + 1 > i){
			return void(cout << "0\n");
		}
		if(current.second != -1){
			int d = i - current.second + current.first - 1;
			ans = overlap(ans, make_pair(current.first - d, current.second + d));
		}
	}
	cout << ans.second - ans.first + 1 << "\n";
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