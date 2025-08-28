#include<bits/stdc++.h>
#define taskname "2035B"
using namespace std;
const int INV = 1000000000 % 11;
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
		vector<int>ans(n, 3), cnt(2, 0), need(2, 0);
		ans.back() = 6;
		for(int i = 0; i < n; i++){
			cnt[i & 1] += ans[i];
		}
		int temp = cnt[0];
		while((cnt[0] - cnt[1]) % 11 != 0){
			need[0]++;
			cnt[0] += 3;
		}
		cnt[0] = temp;
		while((cnt[0] - cnt[1]) % 11 != 0){
			need[1]++;
			cnt[1] += 3;
		}
		bool have_ans = true;
		if(need[n & 1] < need[(n & 1) ^ 1]){
			for(int i = n - 2; need[n & 1] > 0; i -= 2, need[n & 1]--){
				if(i < 0){
					have_ans = false;
					break;
				}
				ans[i] = 6; 
			}
		}
		else{
			for(int i = n - 1; need[(n & 1) ^ 1] > 0; i -= 2, need[(n & 1) ^ 1]--){
				if(i < 0){
					have_ans = false;
					break;
				}
				ans[i] = 6;
			}
		}
		if(have_ans){
			for(int& x : ans){
				cout << x;
			}
			cout << "\n";
		}
		else{
			cout << "-1\n";
		}
	}
}