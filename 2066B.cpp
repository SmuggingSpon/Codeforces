#include<bits/stdc++.h>
#define taskname "2066B"
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
		int n, ans = 0;
		cin >> n;
		vector<int>a;
		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;
			if(x >= n){
				ans++;
			}
			else{
				a.emplace_back(x);
			}
		}
		if(find(a.begin(), a.end(), 0) == a.end()){
			cout << n << "\n";
			continue;
		}
		ans += int(a.size()) - count(a.begin(), a.end(), 0);
		int pos_0 = find(a.begin(), a.end(), 0) - a.begin();
		vector<bool>cnt(n + 3, false);
		vector<int>mex(a.size() + 1);
		mex[a.size()] = 0;
		for(int i = int(a.size()) - 1; i > -1; i--){
			cnt[a[i]] = true;
			mex[i] = mex[i + 1];
			while(cnt[mex[i]]){
				mex[i]++;
			}
		}
		bool can = true;
		for(int i = 0, min_value = n; i < pos_0; i++){
			if((min_value = min(min_value, a[i])) < mex[i + 1]){
				can = false;
				break;
			}
		}
		cout << ans + int(can) << "\n";
	}
}