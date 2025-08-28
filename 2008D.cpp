#include<bits/stdc++.h>
#define taskname "2008D"
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
		vector<int>p(n + 1), ans(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> p[i];
		}
		vector<bool>color(n + 1, false), vis(n + 1, false);
		string s;
		cin >> s;
		for(int i = 0; i < n; ){
			if(s[i++] == '0'){
				color[i] = true;
			}
		}
		for(int i = 1; i <= n; i++){
			if(!vis[i]){
				vector<int>cycle;
				int x = i, cnt = 0;
				while(!vis[x]){
					vis[x] = true;
					cycle.emplace_back(x);
					if(color[x]){
						cnt++;
					}
					x = p[x];
				}
				for(int& j : cycle){
					ans[j] = cnt;
				}
			}
		}
		for(int i = 1; i <= n; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
}