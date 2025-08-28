#include<bits/stdc++.h>
#define taskname "1986C"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, m;
		string s, c;
		cin >> n >> m >> s;
		vector<bool>cnt(n, false);
		for(int i = 0; i < m; i++){
			int x;
			cin >> x;
			cnt[x - 1] = true;
		}
		cin >> c;
		sort(c.begin(), c.end());
		for(int i = 0, index = 0; i < n; i++){
			if(cnt[i]){
				s[i] = c[index++];
			}
		}
		cout << s << "\n";
	}
}