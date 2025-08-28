#include<bits/stdc++.h>
#define taskname "2032E"
using namespace std;
typedef long long ll;
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
		vector<int>a(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		if(n == 1){
			cout << "0\n";
			continue;
		}
		vector<int>nxt(n + 1);
		for(int i = n - (nxt[n] = 2); i > 0; i--){
			nxt[i] = i + 2;
		}
		nxt[n - 1] = 1;
		vector<int>p(n + 1);
		for(int i = 1, cnt = 0; cnt < n; i = nxt[i]){
			p[i] = ++cnt;
		}
		vector<ll>cnt_sub(n + 1, 0);
		int eq = *max_element(a.begin() + 1, a.end());
		for(int i = 1; i <= n; i++){
			int x = eq - a[i];
			cnt_sub[p[nxt[i]]] += x;
			if(p[nxt[i]] + (n >> 1) <= n){
				cnt_sub[p[nxt[i]] + (n >> 1)] -= x;
			} 
			else{
				cnt_sub[1] += x;
				cnt_sub[1 + (n >> 1) - (n - p[nxt[i]] + 1)] -= x;
			}
		}
		for(int i = 2; i <= n; i++){
			cnt_sub[i] += cnt_sub[i - 1];
		}
		vector<ll>ans(n + 1, 0);
		for(int i = 1; i <= n; i++){
			int j = (i == n ? 1 : i + 1);
			ll x = cnt_sub[p[i]];
			ans[p[j]] += x;
			if(p[j] + (n >> 1) <= n){
				ans[p[j] + (n >> 1)] -= x;
			}
			else{
				ans[1] += x;
				ans[1 + (n >> 1) - (n - p[j] + 1)] -= x;
			}
		}
		for(int i = 2; i <= n; i++){
			ans[i] += ans[i - 1];
		}
		for(int i = 1; i <= n; i++){
			cout << ans[p[i]] << " ";
		}
		cout << "\n";
	}
}