#include<bits/stdc++.h>
#define taskname "2031D"
using namespace std;
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
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
		vector<int>prefix_max(n + 1);
		prefix_max[1] = 1;
		for(int i = 2; i <= n; i++){
			prefix_max[i] = (a[i] > a[prefix_max[i - 1]] ? i : prefix_max[i - 1]);
		}
		vector<int>bit(n + 1, 0);
		auto update = [&] (int p, int x){
			for(; p <= n; p += p & -p){
				maximize(bit[p], x);
			}
		};
		auto get = [&] (int p){
			int ans = 0;
			for(; p > 0; p -= p & -p){
				maximize(ans, bit[p]);
			}
			return ans;
		};
		vector<int>to_min(n + 1), ans(n + 1, 0);
		for(int i = n; i > 0; i--){
			to_min[i] = max(i, get(a[i] - 1));
			update(a[i], i);
		}
		for(int i = n; i > 0; i--){
			ans[i] = max(a[prefix_max[i]], ans[to_min[prefix_max[i]]]);
		}
		for(int i = 1; i <= n; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
}