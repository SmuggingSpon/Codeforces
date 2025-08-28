#include<bits/stdc++.h>
#define taskname "508D"
using namespace std;
const int SIZE = 256;
vector<pair<char, char>>g[SIZE][SIZE];
int n, in_deg[SIZE][SIZE], out_deg[SIZE][SIZE];
vector<pair<char, char>>ans;
void dfs(pair<char, char>u){
	while(!g[u.first][u.second].empty()){
		pair<char, char>v = g[u.first][u.second].back();
		g[u.first][u.second].pop_back();
		dfs(v);
	}
	ans.push_back(u);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n;
	memset(in_deg, 0, sizeof(in_deg));
	memset(out_deg, 0, sizeof(out_deg));
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		g[s[0]][s[1]].push_back(make_pair(s[1], s[2]));
		out_deg[s[0]][s[1]]++;
		in_deg[s[1]][s[2]]++;
	}
	vector<pair<char, char>>odd;
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			if(abs(in_deg[i][j] - out_deg[i][j]) > 1){
				return cout << "NO", 0;
			}
			if(abs(in_deg[i][j] - out_deg[i][j]) == 1){
				odd.push_back(make_pair(i, j));
				if(odd.size() > 2){
					return cout << "NO", 0;
				}
			}
		}
	}
	if(!odd.empty()){
		int d = in_deg[odd[0].first][odd[0].second] - out_deg[odd[0].first][odd[0].second];
		if(in_deg[odd[0].first][odd[0].second] > out_deg[odd[0].first][odd[0].second]){
			swap(odd[0], odd[1]);
		}
		dfs(odd[0]);
	}
	else{
		for(int i = 0; i < SIZE; i++){
			for(int j = 0; j < SIZE; j++){
				if(out_deg[i][j] > 0){
					dfs(make_pair(i, j));
					i = SIZE;
					break;
				}
			}
		}
	}
	if(ans.size() != n + 1){
		return cout << "NO", 0;
	}
	reverse(ans.begin(), ans.end());
	cout << "YES\n" << ans[0].first;
	for(int i = 0; i < n + 1; i++){
		cout << ans[i].second;
	}
}