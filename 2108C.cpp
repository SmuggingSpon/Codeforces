#include<bits/stdc++.h>
#define taskname "2108C"
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
		map<int, vector<int>>p;
		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;
			p[-x].emplace_back(i);
		}
		vector<int>parent(n + 2, -1);
		vector<bool>picked(n + 1, false);
		auto find_set = [&] (int i){
			while(i != parent[i]){
				i = parent[i] = parent[parent[i]];
			}
			return i;
		};
		int ans = 0;
		auto merge = [&] (int u, int v){
			if(picked[u = find_set(u)] != picked[v = find_set(v)]){
				ans--;
				picked[u] = picked[v] = true;
			}
			else if(!picked[u] && !picked[v]){
				ans--;
			}
			parent[u] = v;
		};
		for(auto& [foo, ve] : p){
			ans += ve.size();
			for(int& i : ve){
				parent[i] = i;
				if(parent[i - 1] != -1){
					merge(i, i - 1);
				}
				if(parent[i + 1] != -1){
					merge(i, i + 1);
				}
			}
			for(int& i : ve){
				picked[find_set(i)] = true;
			}
		}
		cout << ans << "\n";
	}
}