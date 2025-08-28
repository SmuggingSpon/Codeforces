#include<bits/stdc++.h>
#define taskname "1900F"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int n, q;
	cin >> n >> q;
	vector<int>a(n + 1);
	for(int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	
	auto get_current = [&] (vector<int>&previous, bool not_min){
		vector<int>current;
		for(int i = 0; i < previous.size(); i++){
			if(not_min){
				if((i == 0 || a[previous[i]] < a[previous[i - 1]]) && (i == previous.size() - 1 || a[previous[i]] < a[previous[i + 1]])){
					current.emplace_back(previous[i]); 
				}
			}
			else{
				if((i == 0 || a[previous[i]] > a[previous[i - 1]]) && (i == previous.size() - 1 || a[previous[i]] > a[previous[i + 1]])){
					current.emplace_back(previous[i]); 
				}
			}
		}
		return current;
	};
	
	vector<vector<int>>layer(1, vector<int>(n));
	iota(layer[0].begin(), layer[0].end(), 0);
	for(bool not_min = true; layer.back().size() > 1; not_min ^= 1){
		layer.emplace_back(get_current(layer.back(), not_min));
	}
	
	function<void(int, int, int, vector<int>, vector<int>)>solve;
	solve = [&] (int h, int l, int r, vector<int>L, vector<int>R){
		if(l >= r){
			if(l == r){
				L.emplace_back(layer[h][l]);
			}
			reverse(R.begin(), R.end());
			for(auto& x : R){
				L.emplace_back(x);
			}
			while(L.size() > 1){
				L = get_current(L, ~h & 1);
				h++;
			}
			return (void)(cout << a[L[0]] << "\n");
		}
		L.emplace_back(layer[h][l]);
		L.emplace_back(layer[h][l + 1]);
		L = get_current(L, ~h & 1);
		if(L.back() == layer[h][l + 1]){
			L.pop_back();
		}
		
		R.emplace_back(layer[h][r]);
		R.emplace_back(layer[h][r - 1]);
		R = get_current(R, ~h & 1);
		if(R.back() == layer[h][r - 1]){
			R.pop_back();
		}
		
		solve(h + 1, upper_bound(layer[h + 1].begin(), layer[h + 1].end(), layer[h][l]) - layer[h + 1].begin(), lower_bound(layer[h + 1].begin(), layer[h + 1].end(), layer[h][r]) - layer[h + 1].begin() - 1, L, R);
	};
	for(int _ = 0; _ < q; _++){
		int l, r;
		cin >> l >> r;
		solve(0, l - 1, r - 1, {}, {});
	}
}