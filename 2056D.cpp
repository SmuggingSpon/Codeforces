#include<bits/stdc++.h>
#define taskname "2056D"
using namespace std;
typedef long long ll;
const int lim = 4e5 + 5;
int bit[lim];
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
		ll ans = n;
		vector<int>a(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			ans += ((n - i) >> 1);
		}
		auto update = [&] (int p){
			for(p += n + 5; p < (n << 2); p += p & -p){
				bit[p]++;
			}
		};
		auto get = [&] (int p){
			int ans = 0;
			for(p += n + 5; p > 0; p -= p & -p){
				ans += bit[p];
			}
			return ans;
		};
		auto reset = [&] (){
			for(int i = (n << 2) - 1; i > 0; i--){
				bit[i] = 0;
			}
		};
		for(int median = 1; median < 11; median++){
			vector<int>small(n + 1), large(n + 1);
			small[0] = large[0] = 0;
			for(int i = 1; i <= n; i++){
				small[i] = small[i - 1] - 1 + (int(a[i] < median) << 1);
				large[i] = large[i - 1] - 1 + (int(a[i] > median) << 1);
			}
			vector<int>index;
			for(int i = 0; i <= n; i += 2){
				index.emplace_back(i);
			}
			sort(index.begin(), index.end(), [&] (int i, int j) -> bool{
				return small[i] < small[j] || (small[i] == small[j] && large[i] > large[j]);
			});
			reset();
			for(int& i : index){
				ans += get(large[i] - 1);
				update(large[i]);
			}
			index.clear();
			for(int i = 1; i <= n; i += 2){
				index.emplace_back(i);
			}
			sort(index.begin(), index.end(), [&] (int i, int j) -> bool{
				return small[i] < small[j] || (small[i] == small[j] && large[i] > large[j]);
			});
			reset();
			for(int& i : index){
				ans += get(large[i] - 1);
				update(large[i]);
			}
		}
		reset();
		cout << ans << "\n";
	}
}