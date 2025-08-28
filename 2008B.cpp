#include<bits/stdc++.h>
#define taskname "2008B"
using namespace std;
string s;
int n, cnt_1;
bool check(int r, int c){
	if(cnt_1 != ((r + c - 2) << 1)){
		return false;
	}
	vector<vector<char>>a(r, vector<char>(c));
	for(int i = 0, x = 0, y = 0; i < n; i++){
		a[x][y] = s[i];
		if(++y == c){
			x++;
			y = 0;
		}
	}
	for(int i = 0; i < c; i++){
		if(a[0][i] == '0' || a[r - 1][i] == '0'){
			return false;
		}
	}
	for(int i = 0; i < r; i++){
		if(a[i][0] == '0' || a[i][c - 1] == '0'){
			return false;
		}
	}
	return true;
}
void solve(){
	cin >> n >> s;
	cnt_1 = count(s.begin(), s.end(), '1');
	int x = sqrt(n);
	cout << (x * x == n && check(x, x) ? "Yes\n" : "No\n");
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
