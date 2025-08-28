#include<bits/stdc++.h>
#define taskname "2009D"
using namespace std;
typedef long long ll;
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
		vector<vector<bool>>cnt(2, vector<bool>(n + 3, 0));
		for(int i = 1; i <= n; i++){
			int x, y;
			cin >> x >> y;
			cnt[y][++x] = true;
		}
		int cnt_0 = 0, cnt_1 = 0;
		for(int i = 1; i < n + 2; i++){
			if(cnt[0][i] && cnt[1][i]){
				cnt_0++;
			}
			if(cnt[0][i] && cnt[1][i - 1] && cnt[1][i + 1]){
				cnt_1++;
			}
			if(cnt[1][i] && cnt[0][i - 1] && cnt[0][i + 1]){
				cnt_1++;
			}
		}
		cout << 1LL * cnt_0 * (n - 2) + cnt_1 << "\n";
	}
}