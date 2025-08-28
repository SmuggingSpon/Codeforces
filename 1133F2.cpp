#include<bits/stdc++.h>
#define taskname "1133F2"
using namespace std;
const int lim = 2e5 + 5;
int n, m, D, cnt_spec, p[lim];
bitset<lim>spec;
vector<int>g[lim];
vector<pair<int, int>>ans;
int find_set(int n){
	return n == p[n] ? n : p[n] = find_set(p[n]);
}
bool merge(int a, int b){
	if((a = find_set(a)) != (b = find_set(b))){
		if(spec.test(p[b] = a) && spec.test(b)){
			cnt_spec--;
		}
		if(spec.test(b)){
			spec.set(a);
		}
		return true;
	}
	return false;
}
bool check(){
	if(cnt_spec == D){
		cnt_spec = -1;
		for(int& i : g[1]){
			if(merge(1, i)){
				ans.emplace_back(1, i);
			}
		}
		for(int i = 2; i <= n; i++){
			for(int& j : g[i]){
				if(j > i && merge(i, j)){
					ans.emplace_back(i, j);
				}
			}
		}
		return true;
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n >> m >> D;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	cnt_spec = g[1].size();
	spec.reset();
	for(int& i : g[1]){
		spec.set(i);
	}
	iota(p + 1, p + n + 1, 1);
	if(!check()){
		for(int i = 2; i <= n; i++){
			for(int& j : g[i]){
				if(j > i && merge(i, j)){
					ans.emplace_back(i, j);
					if(check()){
						i = n;
						break;
					}
				}
			}
		}
	}
	if(cnt_spec > -1){
		return cout << "NO", 0;
	}
	cout << "YES\n";
	for(auto& [u, v] : ans){
		cout << u << " " << v << "\n";
	}
}
