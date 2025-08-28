#include<bits/stdc++.h>
#define taskname "2037F"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, m, k;
		cin >> n >> m >> k;
		vector<int>h(n), x(n);
		for(int& v : h){
			cin >> v;
		}
		for(int& v : x){
			cin >> v;
		}
		int low = 1, high = 1e9, ans = -1;
		while(low <= high){
			int mid = (low + high) >> 1, cur = 0;
			map<int, int>cnt;
			for(int i = 0; i < n; i++){
				int N = m - (h[i] + mid - 1) / mid;
				if(N > -1){
					cnt[x[i] - N]++;
					cnt[x[i] + N + 1]--;
				}
			}
			bool can = false;
			for(auto& [u, v] : cnt){
				if((cur += v) >= k){
					can = true;
					break;
				}
			}
			if(can){
				high = (ans = mid) - 1;
			}
			else{
				low = mid + 1;
			}
		}
		cout << ans << "\n";
	}
}