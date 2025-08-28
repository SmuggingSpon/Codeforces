#include<bits/stdc++.h>
#define taskname "2036D"
using namespace std;
const int lim = 1e3 + 5;
char a[lim][lim];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, m;
		cin >> n >> m;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> a[i][j];
			}
		}
		int x = 1, y = 1, u = n, v = m, ans = 0;
		while(x <= u && y <= v){
			string S = "";
			for(int i = y; i <= v; i++){
				S += a[x][i];
			}
			for(int i = x + 1; i <= u; i++){
				S += a[i][v];
			}
			for(int i = v - 1; i >= y; i--){
				S += a[u][i];
			}
			for(int i = u - 1; i > x; i--){
				S += a[i][y];
			}
			if(S.size() > 3){
				for(int i = 0; i < 3; i++){
					S += S[i];
				}
				for(int i = 3; i < S.size(); i++){
					if(S[i - 3] == '1' && S[i - 2] == '5' && S[i - 1] == '4' && S[i] == '3'){
						ans++;
					}
				}
			}
			x++;
			y++;
			u--;
			v--;
		}
		cout << ans << "\n";
	}
}