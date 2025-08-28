#include<bits/stdc++.h>
#define taskname "2008E"
using namespace std;
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
const int lim = 2e5 + 5;
int cnt[lim][26][2];
int get(int l, int r, int c, bool parity){
	return cnt[r][c][parity] - cnt[l - 1][c][parity];
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int i = 0; i < 26; i++){
		cnt[0][i][0] = cnt[0][i][1] = 0;
	}
	for(int _ = 0; _ < _t; _++){
		int n;
		string s;
		cin >> n >> s;
		s = '$' + s;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < 26; j++){
				cnt[i][j][0] = cnt[i - 1][j][0];
				cnt[i][j][1] = cnt[i - 1][j][1];
			}
			cnt[i][s[i] - 97][i & 1]++;
		}
		if(n & 1){
			int ans = 0;
			for(int i = 1; i <= n; i++){
				int cnt_0 = 0, cnt_1 = 0;
				bool parity = i & 1;
				for(int j = 0; j < 26; j++){
					maximize(cnt_0, get(1, i - 1, j, parity) + get(i + 1, n, j, !parity));
					maximize(cnt_1, get(1, i - 1, j, !parity) + get(i + 1, n, j, parity));
				}
				maximize(ans, cnt_0 + cnt_1);
			}
			cout << n - ans << "\n";
		}
		else{
			int cnt_0 = 0, cnt_1 = 0;
			for(int i = 0; i < 26; i++){
				maximize(cnt_0, cnt[n][i][0]);
				maximize(cnt_1, cnt[n][i][1]);
			}
			cout << n - cnt_0 - cnt_1 << "\n";
		}
	}
}