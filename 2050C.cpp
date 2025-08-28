#include<bits/stdc++.h>
#define taskname "2050C"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		string s;
		cin >> s;
		vector<int>state = {0};
		for(char& c : s){
			c -= '0';
			sort(state.begin(), state.end());
			state.resize(unique(state.begin(), state.end()) - state.begin());
			vector<int>next_state;
			for(int& i : state){
				next_state.emplace_back((i + c) % 9);
				if(c < 4){
					next_state.emplace_back((i + c * c) % 9);
				}
			}
			swap(state, next_state);
		}
		cout << (find(state.begin(), state.end(), 0) != state.end() ? "YES\n" : "NO\n");
	}
}