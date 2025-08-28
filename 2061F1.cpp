#include<bits/stdc++.h>
#define taskname "2061F1"
using namespace std;
void solve(){
	int ans = 0;
	string s, t;
	cin >> s >> t;
	deque<pair<char, int>>d;
	for(int i = 0; i < s.size(); i++){
		if(i == 0 || s[i] != s[i - 1]){
			d.emplace_back(s[i], 1);
		}
		else{
			d.back().second++;
		}
	}
	vector<pair<char, int>>block;
	for(int i = 0; i < t.size(); i++){
		if(i == 0 || t[i] != t[i - 1]){
			block.emplace_back(t[i], 1);
		}
		else{
			block.back().second++;
		}
	}
	for(int _i = 0; _i < block.size(); _i++){
		auto& [c, cnt] = block[_i];
		if(d.empty() || (d.size() == 1 && d.front().first != c) || (d.front().first == c && d.front().second > cnt)){
			return void(cout << "-1\n");
		}
		if(d.front().first != c){
			ans++;
			int temp = d.front().second;
			d.pop_front();
			if(d.size() > 1){
				d[1].second += temp;
			}
			else{
				d.emplace_back(((c - 48) ^ 1) + 48, temp);
			}
			_i--;
		}
		else if(d.front().second < cnt){
			if(d.size() < 3){
				return void(cout << "-1\n");
			}
			ans++;
			int x = d.front().second;
			d.pop_front();
			pair<int, int>temp = d.front();
			d.pop_front();
			x += d.front().second;
			d.pop_front();
			if(!d.empty()){
				d.front().second += temp.second;
			}
			else{
				d.emplace_front(temp);
			}
			d.emplace_front(c, x);
			_i--;
		}
		else{
			d.pop_front();
		}
	}
	cout << ans << "\n";
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		solve();
	}
}