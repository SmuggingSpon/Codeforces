#include<bits/stdc++.h>
#define taskname "1980E"
using namespace std;
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
		vector<vector<int>>a(n, vector<int>(m));
		for(vector<int>& u : a){
			for(int& v : u){
				cin >> v;
			}
		}
		vector<int>row(n * m + 1), col(n * m + 1);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				int x;
				cin >> x;
				row[x] = i;
				col[x] = j;
			}
		}
		bool ans = true;
		for(int i = 0; i < n; i++){
			for(int j = 1; j < m; j++){
				if(row[a[i][0]] != row[a[i][j]]){
					ans = false;
					i = n;
					break;
				}
			}
		}
		for(int j = 0; j < m; j++){
			for(int i = 1; i < n; i++){
				if(col[a[0][j]] != col[a[i][j]]){
					ans = false;
					j = m;
					break;
				}
			}
		}
		cout << (ans ? "YES\n" : "NO\n");
	}
}