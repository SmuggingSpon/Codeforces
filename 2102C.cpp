#include<bits/stdc++.h>
#define taskname "2102C"
using namespace std;
typedef long long ll;
const int lim = 505;
int n, cnt, a[lim][lim];
void work(int x, int y, int u, int v){
	if(x == u && y == v){
		a[x][y] = cnt++;
		return;
	}
	for(int i = y + 1; i <= v; i++){
		a[x][i] = cnt++;
	}
	for(int i = x + 1; i <= u; i++){
		a[i][v] = cnt++;
	}
	for(int i = v - 1; i >= y; i--){
		a[u][i] = cnt++;
	}
	for(int i = u - 1; i >= x; i--){
		a[i][y] = cnt++;
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
		cin >> n;
		cnt = 0;
		if(n & 1){
			int p = (n >> 1) + 1;
			work(p, p, p, p);
			for(int d = 1; d <= (n >> 1); d++){
				work(p - d, p - d, p + d, p + d);
			}
		}
		else{
			int p = n >> 1;
			work(p, p, p + 1, p + 1);
			for(int d = 1; d < (n >> 1); d++){
				work(p - d, p - d, p + d + 1, p + d + 1);
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
	}
}