#include<bits/stdc++.h>
#define taskname "1900C"
using namespace std;
void solve(){
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	s = '#' + s;

	vector<int>l(n + 1), r(n + 1), f(n + 1);
	
	for(int i = 1; i <= n; i++){
		cin >> l[i] >> r[i];
	}
	
	f[1] = 0;
	queue<int>q;
	q.push(1);
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(l[u] != 0){
			f[l[u]] = f[u] + int(s[u] != 'L');
			q.push(l[u]);
		}
		if(r[u] != 0){
			f[r[u]] = f[u] + int(s[u] != 'R');
			q.push(r[u]);
		}
	}
	
	int ans = INT_MAX;
	
	for(int i = 1; i <= n; i++){
		if(l[i] == 0 && r[i] == 0){
			ans = min(ans, f[i]);
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