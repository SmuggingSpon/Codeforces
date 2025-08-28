#include<bits/stdc++.h>
#define taskname "1167E"
using namespace std;
typedef long long ll;
const int lim = 1e6 + 5;
struct FenwickTree{
	int bit[lim];
	FenwickTree(){
		memset(bit, 0, sizeof(bit));
	}
	void update(int p, int x){
		for(; p < lim; p += p & -p){
			bit[p] += x;
		}
	}
	int get(int p){
		int ans = 0;
		for(; p > 0; p -= p & -p){
			ans += bit[p];
		}
		return ans;
	}
	int get(int l, int r){
		return get(r) - get(l - 1);
	}
};
FenwickTree L, R;
int n, x;
vector<int>p[lim];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n >> x;
	for(int i = 1; i <= n; i++){
		int v;
		cin >> v;
		p[v].emplace_back(i);
	}
	ll inv = 0, ans = 0;
	for(int i = 1; i <= x; i++){
		for(int& P : p[i]){
			inv += R.get(P + 1, n);
			R.update(P, 1);
		}
	}
	for(int l = 1, r = 1, cnt_l = 0; r <= x; r++){
		for(int& P : p[r]){
			inv -= R.get(1, P - 1) + L.get(P + 1, n);
			R.update(P, -1);
		}
		if(inv == 0){
			while(l < r){
				if(p[l].empty() || (R.get(1, p[l].back() - 1) == 0 && L.get(p[l][0] + 1, n) == 0)){
					for(int& P : p[l]){
						L.update(P, 1);
					}
					l++;
				}
				else{
					break;
				}
			}
			ans += l;
		}
	}
	cout << ans;
}