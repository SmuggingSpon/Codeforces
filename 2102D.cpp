#include<bits/stdc++.h>
#define taskname "2102D"
using namespace std;
const int lim = 2e5 + 5;
int n, a[lim], bit[lim];
vector<int>value[2];
void update(int p){
	for(; p <= n; p += p & -p){
		bit[p]++;
	}
}
int get(int p){
	int ans = 0;
	for(; p > 0; p -= p & -p){
		ans += bit[p];
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		cin >> n;
		bool inv = false;
		fill(bit + 1, bit + n + 1, 0);
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			value[i & 1].emplace_back(a[i]);
			update(a[i]);
			if((i - get(a[i])) & 1){
				inv = !inv;
			}
		}
		sort(value[0].begin(), value[0].end(), greater<int>());
		sort(value[1].begin(), value[1].end(), greater<int>());
		for(int i = 1; i <= n; i++){
			a[i] = value[i & 1].back();
			value[i & 1].pop_back();
		}
		fill(bit + 1, bit + n + 1, 0);
		for(int i = 1; i <= n; i++){
			update(a[i]);
			if((i - get(a[i])) & 1){
				inv = !inv;
			}
		}
		if(inv){
			swap(a[n], a[n - 2]);
		}
		for(int i = 1; i <= n; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
	}
}