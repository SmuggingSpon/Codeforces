#include<bits/stdc++.h>
#define taskname "2048E"
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
		if((n << 1) <= m){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		int M = m;
		m = (n << 1) - 1;
		vector<vector<int>>ans(n << 1, vector<int>(m));
		vector<int>vertex(n << 1);
		iota(vertex.begin(), vertex.end(), 0);
		for(int color = 1; color <= n; color++){
			if(color > 1){
				swap(vertex[0], vertex[1]);
			}
			ans[vertex[0]][0] = color;
			for(int i = 2; i < (n << 1); i++){
				ans[vertex[i]][i - 2] = ans[vertex[i]][i - 1] = color;
			}
			ans[vertex[1]][m - 1] = color;
			swap(vertex[0], vertex[1]);
			vertex.emplace_back(vertex[0]);
			vertex.emplace_back(vertex[1]);
			vertex.erase(vertex.begin());
			vertex.erase(vertex.begin());
		}
		for(int i = 0; i < (n << 1); i++){
			for(int j = 0; j < M; j++){
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
	}
}