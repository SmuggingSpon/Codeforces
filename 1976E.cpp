#include<bits/stdc++.h>
#define taskname "1976E"
using namespace std;
const int mod = 998244353;
const int lim = 3e5 + 5;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int n, q, ans = 1;
	cin >> n >> q;
	vector<int>index(n + 1, -1), a(q << 1 | 1);
	index[n] = 0;
	vector<bool>leaf(q << 1 | 1, true), check(n + 1, false);
	for(int i = 1; i < (q << 1); i += 2){
		cin >> a[i];
	}
	vector<vector<int>>g(q << 1 | 1);
	for(int i = 2; i <= (q << 1); i += 2){
		cin >> a[i];
		leaf[index[max(a[i], a[i - 1])]] = false;
		g[index[max(a[i], a[i - 1])]].emplace_back(i - 1);
		g[index[max(a[i], a[i - 1])]].emplace_back(i);
		index[a[i]] = i;
		index[a[i - 1]] = i - 1;
	}
	vector<int>p;
	function<void(int)>dfs;
	dfs = [&] (int s){
		if(leaf[s]){
			check[a[s]] = true;
			p.emplace_back(a[s]);	
			return;
		}	
		dfs(g[s][0]);
		dfs(g[s][1]);
	};
	dfs(0);
	vector<int>range;
	if(!p.empty()){
		range.emplace_back(p[0]);
		range.emplace_back(p.back());
	}
	for(int i = 1; i < p.size(); i++){
		range.emplace_back(max(p[i - 1], p[i]));
	}
	sort(range.begin(), range.end(), greater<int>());
	for(int i = n, cnt = 0, ptr = 0; i > 0; i--){
		if(!check[i]){
			while(ptr < range.size() && range[ptr] > i){
				ptr++;
			}
			ans = 1LL * ans * (ptr + cnt++) % mod;
		}
	}
	cout << ans << "\n";
}