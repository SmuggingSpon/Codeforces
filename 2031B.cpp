#include<bits/stdc++.h>
#define taskname "2031B"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n;
		cin >> n;
		vector<int>p(n + 1);
		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;
			p[x] = i;
		}
		bool ans = true;
		for(int i = n; i > 1; i--){
			if(p[i] != i){
				if(p[i - 1] == i && abs(p[i] - p[i - 1]) == 1){
					swap(p[i], p[i - 1]);
				}
				else{
					ans = false;
					break;
				}
			}
		}
		cout << (ans ? "YES\n" : "NO\n");
	}
}