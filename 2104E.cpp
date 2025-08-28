#include<bits/stdc++.h>
#define taskname "2104E"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int n, k;
	cin >> n >> k;
	vector<vector<int>>next(n + 2, vector<int>(k, n + 1));
	string s;
	cin >> s;
	for(char& c : s){
		c -= 97;
	}
	s = '#' + s;
	for(int i = n - 1; i > -1; i--){
		next[i] = next[i + 1];
		next[i][s[i + 1]] = i + 1;
	}
	vector<vector<int>>up(n + 2, vector<int>(20, n + 1));
	for(int i = n; i > -1; i--){
		up[i][0] = *max_element(next[i].begin(), next[i].end());
		for(int j = 1; j < 20; j++){
			up[i][j] = up[up[i][j - 1]][j - 1];
		}
	}
	int q;
	cin >> q;
	for(int _ = 0; _ < q; _++){
		string t;
		cin >> t;
		int p = 0;
		for(char& c : t){
			p = next[p][c - 97];
		}
		if(p == n + 1){
			cout << "0\n";
			continue;
		}
		int ans = 0;
		for(int i = 19; i > -1; i--){
			if(up[p][i] < n + 1){
				p = up[p][i];
				ans |= 1 << i;
			}
		}
		cout << ans + 1 << "\n";
	}
}