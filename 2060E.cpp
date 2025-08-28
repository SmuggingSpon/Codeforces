#include<bits/stdc++.h>
#define taskname "2060E"
using namespace std;
struct DSU{
	vector<int>parent, cnt;
	DSU(){}
	DSU(int n){
		parent.assign(n + 1, 0);
		cnt.assign(n + 1, 0);
		iota(parent.begin(), parent.end(), 0);
	}
	int find_set(int n){
		return n == parent[n] ? n : parent[n] = find_set(parent[n]);
	}
	void merge(int a, int b){
		if((a = find_set(a)) != (b = find_set(b))){
			cnt[parent[b] = a] += cnt[b] + 1;
		}
	}
};
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, m1, m2, ans = 0;
		cin >> n >> m1 >> m2;
		DSU g1(n), g2(n);
		vector<pair<int, int>>edge(m1);
		for(auto& [u, v] : edge){
			cin >> u >> v;
		}
		for(int i = 0; i < m2; i++){
			int u, v;
			cin >> u >> v;
			g2.merge(u, v);
		}
		for(auto& [u, v] : edge){
			if(g2.find_set(u) != g2.find_set(v)){
				ans++;
			}
			else{
				g1.merge(u, v);
			}
		}
		vector<vector<int>>part(n + 1);
		for(int i = 1; i <= n; i++){
			part[g2.find_set(i)].emplace_back(i);
		}
		vector<bool>same(n + 1, false);
		for(int i = 1; i <= n; i++){
			if(i == g2.find_set(i)){
				for(int& j : part[i]){
					if(!same[g1.find_set(j)]){
						same[g1.find_set(j)] = true;
						ans++;
					}
				}
				ans--;
				for(int& j : part[i]){
					same[g2.find_set(j)] = false;
				}
			}
		}
		cout << ans << "\n";
	}
}