#include<bits/stdc++.h>
#define taskname "1954B"
using namespace std;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
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
		vector<int>a(n);
		for(int& x : a){
			cin >> x;
		}
		if(a[0] != a.back()){
			cout << "0\n";
			continue;
		}
		vector<pair<int, int>>cnt(1, make_pair(a[0], 1));
		for(int i = 1; i < n; i++){
			if(a[i] == cnt.back().first){
				cnt.back().second++;
			}
			else{
				cnt.emplace_back(a[i], 1);
			}
		}
		if(cnt.size() == 1){
			cout << "-1\n";
			continue;
		}
		bool need_ans = true;
		for(int i = 1; i < cnt.size(); i += 2){
			if((i + 1 < cnt.size() && cnt[i + 1].first != a[0]) || cnt[i].second > 1){
				cout << "0\n";
				need_ans = false;
				break;
			}
		}
		if(need_ans){
			int ans = INT_MAX;
			for(int i = 0; i < cnt.size(); i += 2){
				minimize(ans, cnt[i].second);
			}
			cout << ans << "\n";
		}
	}
}