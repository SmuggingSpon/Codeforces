#include<bits/stdc++.h>
#define taskname "2055C"
using namespace std;
typedef long long ll;
const ll INF = 1e18;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, m;
		string s;
		cin >> n >> m >> s;
		vector<vector<ll>>a(n + 1, vector<ll>(m + 1));
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> a[i][j];
			}
		}
		vector<int>row(n + 1, 0), col(m + 1, 0);
		int x = 1, y = 1;
		for(char& c : s){
			row[x]++;
			col[y]++;
			if(c == 'R'){
				a[x][y++] = INF;
			}
			else{
				a[x++][y] = INF;
			}
		}
		row[n]++;
		col[m]++;
		a[n][m] = INF;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(a[i][j] == INF){
					if(row[i] == 1){
						a[i][j] = 0;
						for(int t = 1; t <= m; t++){
							if(t != j){
								a[i][j] -= a[i][t];
							}
						}
					}
					else{
						a[i][j] = 0;
						for(int t = 1; t <= n; t++){
							if(t != i){
								a[i][j] -= a[t][j];
							}
						}
					}
					row[i]--;
					col[j]--;
				}
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
	}
}