#include<bits/stdc++.h>
#define taskname "1982D"
using namespace std;
typedef long long ll;
const int lim = 505;
int a[lim][lim], cnt[lim][lim];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	memset(cnt, 0, sizeof(cnt));
	for(int _ = 0; _ < _t; _++){
		int n, m, k;
		cin >> n >> m >> k;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> a[i][j];
			}
		}
		ll d = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				char c;
				cin >> c;
				cnt[i][j] = (c == '0' ? 1 : -1) + cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1]; 
				if(c == '0'){
					d += a[i][j];	
				}
				else{
					d -= a[i][j];
				}
			}
		}
		int g = 0;
		for(int i = k; i <= n; i++){
			for(int j = k; j <= m; j++){
				int current = cnt[i][j] - cnt[i - k][j] - cnt[i][j - k] + cnt[i - k][j - k];
				if(current != 0){
					g = __gcd(g, abs(current));	
				}
			}
		}
		if((g == 0 && d == 0) || (g != 0 && d % g == 0)){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}