#include<bits/stdc++.h>
#define taskname "579B"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int n;
	cin >> n;
	vector<vector<int>>a(n << 1 | 1, vector<int>(n << 1 | 1));
	vector<pair<int, int>>p;
	for(int i = 2; i <= (n << 1); i++){
		for(int j = 1; j < i; j++){
			cin >> a[i][j];
			p.emplace_back(i, j);
		}
	}
	sort(p.begin(), p.end(), [&] (auto i, auto j){
		return a[i.first][i.second] > a[j.first][j.second];
	});
	vector<bool>vis(n << 1 | 1, false);
	vector<int>ans(n << 1 | 1);
	for(auto& [i, j] : p){
		if(!vis[i] && !vis[j]){
			vis[i] = vis[j] = true;
			ans[ans[j] = i] = j;
		}
	}
	for(int i = 1; i <= (n << 1); i++){
		cout << ans[i] << " ";
	}
}