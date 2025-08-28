#include<bits/stdc++.h>
#define taskname "1934C"
using namespace std;
int ask(int x, int y){
	cout << "? " << x << " " << y << endl;
	int ans;
	cin >> ans;
	return ans;
}
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
		int up_left = ask(1, 1), up_right = ask(1, m), down_left = ask(n, 1);
		int double_y = up_left - up_right + m + 1, x = up_left + 2 - (double_y >> 1);
		if(double_y > 0 && (~double_y & 1)){
			int y = double_y >> 1;
			if(x > 0 && x <= n && y <= m && ask(x, y) == 0){
				cout << "! " << x << " " << y << endl;
				continue;
			}
		}
		cout << "! " << (x = (up_left - down_left + n + 1) >> 1) << " " << up_left - x + 2 << endl;		
	}
}