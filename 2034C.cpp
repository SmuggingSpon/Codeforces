#include<bits/stdc++.h>
#define taskname "2034C"
using namespace std;
void move(int& i, int& j, char d){
	if(d == 'U'){
		i--;
	}
	else if(d == 'D'){
		i++;
	}
	else if(d == 'L'){
		j--;
	}
	else{
		j++;
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
		vector<vector<char>>a(n, vector<char>(m));
		vector<pair<int, int>>p;
		vector<vector<bool>>repeat(n, vector<bool>(m, false));
		vector<vector<int>>id(n, vector<int>(m, -1));
		auto check = [&] (int i, int j){
			return i > -1 && i < n && j > -1 && j < m && (repeat[i][j] || a[i][j] == '?');
		};
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> a[i][j];
			}
		}
		int ans = 0;
		for(int i = 0, cnt_id = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(id[i][j] == -1 && a[i][j] != '?'){
					int x = i, y = j, cnt = 0;
					vector<pair<int, int>>p;
					while(true){
						cnt++;
						id[x][y] = cnt_id;
						p.emplace_back(x, y);
						move(x, y, a[x][y]);
						if(x == n || y == m || x == -1 || y == -1 || id[x][y] != -1 || a[x][y] == '?'){
							break;
						}
					}
					cnt_id++;
					if(x == n || y == m || x == -1 || y == -1 || (a[x][y] != '?' && id[x][y] != id[i][j] && !repeat[x][y])){
						continue;
					}
					ans += cnt;
					for(auto& [u, v] : p){
						repeat[u][v] = true;
					}
				}
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(a[i][j] == '?' && (check(i - 1, j) || check(i + 1, j) || check(i, j - 1) || check(i, j + 1))){
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
}