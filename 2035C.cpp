#include<bits/stdc++.h>
#define taskname "2035C"
using namespace std;
template<class T>bool maximize(T& a, T b){
	if(a < b){
		a = b;
		return true;
	}
	return false;
}
pair<int, vector<int>>get_ans(int n){
	vector<bool>cnt(n + 1, false);
	vector<pair<int, int>>last(1, make_pair(1, 5));
	cnt[1] = cnt[5] = true;
	int res = 1;
	for(int i = 2; true; i <<= 1){
		res |= i;
		if((i << 1) <= n){
			cnt[i] = cnt[(i << 1) - 1] = true;
			last.emplace_back(i, (i << 1) - 1);
		}
		else{
			cnt[i] = true;
			last.emplace_back(i, -1);
			break;
		}
	}
	vector<int>ans;
	for(int i = 1; i <= n; i++){
		if(!cnt[i]){
			ans.emplace_back(i);
		}
	}
	for(auto& [x, y] : last){
		ans.emplace_back(x);
		if(y != -1){
			ans.emplace_back(y);
		}
	}
	return make_pair(res, ans);
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
		if(n < 7){
			vector<int>p(n), P;
			iota(p.begin(), p.end(), 1);
			int ans = -1;
			do{
				int k = 0;
				for(int i = 0; i < n; i++){
					if(i & 1){
						k |= p[i];
					}
					else{
						k &= p[i];
					}
				}
				if(maximize(ans, k)){
					P = p;
				}
			} while(next_permutation(p.begin(), p.end()));
			cout << ans << "\n";
			for(int& x : P){
				cout << x << " ";
			}
			cout << "\n";
			continue;
		}
		pair<int, vector<int>>ans = get_ans(n - (n & 1));
		if(n & 1){
			ans.first &= n;
			ans.second.emplace_back(n);
		}
		cout << ans.first << "\n";
		for(int& x : ans.second){
			cout << x << " ";
		}
		cout << "\n";
	}
}
