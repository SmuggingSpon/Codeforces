#include<bits/stdc++.h>
#define taskname "1986B"
using namespace std;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
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
		int n, m;
		cin >> n >> m;
		vector<vector<int>>a(n + 2, vector<int>(m + 2, 0));
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> a[i][j];
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				minimize(a[i][j], max(max(a[i - 1][j], a[i + 1][j]), max(a[i][j - 1], a[i][j + 1])));
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
	}
}