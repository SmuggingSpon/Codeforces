#include<bits/stdc++.h>
#define taskname "2060B"
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
		cin >> n >> m;
		vector<int>p(n * m);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				int x;
				cin >> x;
				p[x] = i;
			}
		}
		vector<bool>cnt(n, false);
		bool can = true;
		for(int i = 0; i < n; i++){
			if(cnt[p[i]]){
				can = false;
				break;
			}
			cnt[p[i]] = true;
		}
		for(int i = n; i < n * m; i++){
			if(p[i] != p[i - n]){
				can = false;
				break;
			}
		}
		if(can){
			for(int i = 0; i < n; i++){
				cout << p[i] + 1 << " ";
			}
			cout << "\n";
		}
		else{
			cout << "-1\n";
		}
	}
}
