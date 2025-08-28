#include<bits/stdc++.h>
#define taskname "2069B"
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
		vector<vector<int>>a(n + 2, vector<int>(m + 2, -1));
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> a[i][j];
				a[i][j]--;
			}
		}
		vector<int>cnt(n * m, 0);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(a[i][j] != -1 && cnt[a[i][j]] < 2){
					int color = a[i][j], C = 0;
					queue<pair<int, int>>q;
					q.emplace(i, j);
					while(!q.empty()){
						auto [x, y] = q.front();
						q.pop();
						if(a[x][y] == color){
							a[x][y] = -1;
							C++;
							q.emplace(x - 1, y);
							q.emplace(x + 1, y);
							q.emplace(x, y - 1);
							q.emplace(x, y + 1);
						}
					}
					if(C > 1){
						cnt[color] = 2;
					}
					else{
						cnt[color] = 1;
					}
				}
			}
		}
		cout << accumulate(cnt.begin(), cnt.end(), 0) - *max_element(cnt.begin(), cnt.end()) << "\n";
	}
}