#include<bits/stdc++.h>
#define taskname "1902D"
using namespace std;
const int lim = 2e5 + 5;
int x[lim], y[lim], r_x[lim], r_y[lim];
map<pair<int, int>, int>u, v;
map<pair<int, int>, vector<int>>pos;
map<pair<int, int>, bool>exist;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int n, q, X = 0, Y = 0;
	string s;
	cin >> n >> q >> s;
	s = '#' + s;
	for(int i = 1; i <= n; i++){
		x[i] = y[i] = 0;
		if(s[i] == 'U') y[i] = 1;
		else if(s[i] == 'D') y[i] = -1;
		else if(s[i] == 'L') x[i] = -1;
		else x[i] = 1;
		if(u[make_pair(X += x[i], Y += y[i])] == 0){
			u[make_pair(X, Y)] = i;
		}
		v[make_pair(X, Y)] = i;
	}
	X = Y = x[0] = y[0] = r_x[n + 1] = r_y[n + 1] = 0;
	for(int i = n; i > 0; i--){
		pos[make_pair(r_x[i] = r_x[i + 1] + x[i], r_y[i] = r_y[i + 1] + y[i])].emplace_back(i);
		exist[make_pair(r_x[i], r_y[i])] = true;
	}
	for(auto& [whocare, a] : pos){
		reverse(a.begin(), a.end());
	}
	for(int i = 2; i <= n; i++){
		x[i] += x[i - 1];
		y[i] += y[i - 1];
	}
	
	for(int _ = 0; _ < q; _++){
		int _x, _y, l, r;
		cin >> _x >> _y >> l >> r;
		auto u_it = u.find(make_pair(_x, _y));
		auto v_it = v.find(make_pair(_x, _y));
		if((_x == 0 && _y == 0) || (u_it != u.end() && u_it->second < l) || (v_it != v.end() && v_it->second > r)){
			cout << "YES\n";
		}
		else{
			X = x[l - 1];
			Y = y[l - 1];
			if(X == _x && Y == _y){
				cout << "YES\n";
			}
			else{
				if(exist.find(make_pair(X = _x - X + r_x[r + 1], Y = _y - Y + r_y[r + 1])) != exist.end()){
					auto it = lower_bound(pos[make_pair(X, Y)].begin(), pos[make_pair(X, Y)].end(), l);
					if(it != pos[make_pair(X, Y)].end() && *it <= r){
						cout << "YES\n";
					}
					else{
						cout << "NO\n";
					}
				}
				else{
					cout << "NO\n";
				}
			}
		}
	}
}