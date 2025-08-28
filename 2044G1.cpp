#include<bits/stdc++.h>
#define taskname "2044G1"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n;
		cin >> n;
		vector<vector<int>>g(n + 1);
		vector<int>deg(n + 1, 0);
		for(int i = 1; i <= n; i++){
			int j;
			cin >> j;
			g[i].emplace_back(j);
			deg[j]++;
		}
		int ans = 2;
		vector<int>cur;
		for(int i = 1; i <= n; i++){
			if(deg[i] == 0){
				cur.emplace_back(i);
			}
		}
		while(!cur.empty()){
			ans++;
			vector<int>nxt_cur;
			for(int& i : cur){
				for(int& j : g[i]){
					if(--deg[j] == 0){
						nxt_cur.emplace_back(j);
					}
				}
			}
			swap(cur, nxt_cur);
		}
		cout << ans << "\n";
	}
}