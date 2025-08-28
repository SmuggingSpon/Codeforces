#include<bits/stdc++.h>
#define taskname "2033E"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t; 
	for(int _ = 0; _ < _t; _++){
		int n, ans = 0;
		cin >> n;
		vector<int>p(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> p[i];
		}
		for(int i = 1; i <= n; i++){
			if(p[i] != -1){
				int cnt = 1, x = p[i];
				p[i] = -1;
				while(p[x] != -1){
					int nxt = p[x];
					p[x] = -1;
					x = nxt;
					cnt++;
				}
				ans += (cnt - 1) >> 1;
			}
		}
		cout << ans << "\n";
	}
}