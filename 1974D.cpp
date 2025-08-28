#include<bits/stdc++.h>
#define taskname "1974D"
using namespace std;
int get_id(char ch){
	if(ch == 'N'){
		return 0;
	}
	if(ch == 'S'){
		return 1;
	}
	if(ch == 'E'){
		return 2;
	}
	return 3;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n;
		string s;
		cin >> n >> s;
		vector<vector<int>>p(4);
		for(int i = 0; i < n; i++){
			p[get_id(s[i])].emplace_back(i);
		}
		if((p[get_id('N')].size() & 1) != (p[get_id('S')].size() & 1) || (p[get_id('E')].size() & 1) != (p[get_id('W')].size() & 1)){
			cout << "NO\n";
			continue;
		}
		vector<bool>ans(n, false);
		if(p[get_id('N')].size() & 1){
			ans[p[get_id('N')].back()] = ans[p[get_id('S')].back()] = true;
			p[get_id('N')].pop_back();
			p[get_id('S')].pop_back();
			if(p[get_id('E')].size() & 1){
				p[get_id('E')].pop_back();
				p[get_id('W')].pop_back();
			}
		}
		else if(p[get_id('E')].size() & 1){
			ans[p[get_id('E')].back()] = ans[p[get_id('W')].back()] = true;
			p[get_id('E')].pop_back();
			p[get_id('W')].pop_back();
		}
		for(int i = 0; i < 4; i++){
			for(int j = p[i].size() >> 1; j < p[i].size(); j++){
				ans[p[i][j]] = true;
			}
		}
		if(find(ans.begin(), ans.end(), true) == ans.end() || find(ans.begin(), ans.end(), false) == ans.end()){
			cout << "NO\n";
			continue;
		}
		for(int i = 0; i < n; i++){
			cout << (ans[i] ? 'R' : 'H');
		}
		cout << "\n";
	}
}