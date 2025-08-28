#include<bits/stdc++.h>
#define taskname "2060G"
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int>a(n), b(n);
	for(int& x : a){
		cin >> x;
	}
	for(int& x : b){
		cin >> x;
	}
	vector<int>p(n);
	iota(p.begin(), p.end(), 0);
	sort(p.begin(), p.end(), [&] (int i, int j) -> bool{
		return min(a[i], b[i]) < min(a[j], b[j]);
	});
	vector<int>id(n << 1 | 1);
	for(int i = 0; i < n; i++){
		id[min(a[p[i]], b[p[i]])] = i;
	}
	for(int i = 0; i < n; i++){
		while(id[min(a[i], b[i])] != i){
			int x = id[min(a[i], b[i])];
			swap(a[i], b[x]);
			swap(a[x], b[i]);
		}
	}
	vector<int>bit(n << 1 | 1, 0);
	auto update = [&] (int p){
		for(; p <= (n << 1); p += p & -p){
			bit[p]++;
		}
	};
	auto get = [&] (int p){
		int ans = 0;
		for(; p > 0; p -= p & -p){
			ans += bit[p];
		}
		return ans;
	};
	bool free = false, parity = false;
	for(int i = 0, j = 0; i < n; i++){
		if(i > 0 && max(a[i], b[i]) < max(a[i - 1], b[i - 1])){
			return void(cout << "NO\n");
		}
		update(a[i]);
		update(b[i]);
		if(get(max(a[i], b[i])) == max(a[i], b[i])){
			if((i - j + 1) & 1){
				free = true;
			}
			j = i + 1;
		}
		if(a[i] > b[i]){
			parity = !parity;
		}
	}
	cout << (free || !parity ? "YES\n" : "NO\n");
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