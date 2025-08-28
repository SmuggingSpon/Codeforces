#include<bits/stdc++.h>
#define taskname "15D"
using namespace std;
typedef long long ll;
const int lim = 1e3 + 5;
int n, m, a, b, h[lim][lim], min_col[lim][lim];
ll f[lim][lim];
bitset<lim>vis[lim];
ll cost(int H, int i, int j){
	return f[i + a - 1][j + b - 1] - f[i + a - 1][j - 1] - f[i - 1][j + b - 1] + f[i - 1][j - 1] - 1LL * H * a * b;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	memset(f, 0, sizeof(f));
	cin >> n >> m >> a >> b;
	for(int i = 1; i <= n; i++){
		vis[i].reset();
		for(int j = 1; j <= m; j++){
			cin >> h[i][j];
			f[i][j] = f[i][j - 1] + f[i - 1][j] - f[i - 1][j - 1] + h[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		deque<int>d;
		for(int j = 1; j <= m; j++){
			while(!d.empty() && h[i][d.back()] >= h[i][j]){
				d.pop_back();
			}
			if(!d.empty() && d.front() + b == j){
				d.pop_front();
			}
			d.push_back(j);
			if(j >= b){
				min_col[i][j - b + 1] = h[i][d.front()];
			}
		}
	}
	vector<tuple<ll, int, int>>land;
	for(int j = 1; j + b - 1 <= m; j++){
		deque<int>d;
		for(int i = 1; i <= n; i++){
			while(!d.empty() && min_col[d.back()][j] >= min_col[i][j]){
				d.pop_back();
			}
			if(!d.empty() && d.front() + a == i){
				d.pop_front();
			}
			d.push_back(i);
			if(i >= a){
				land.emplace_back(cost(min_col[d.front()][j], i - a + 1, j), i - a + 1, j);
			}
		}
	}
	sort(land.begin(), land.end());
	vector<tuple<ll, int, int>>ans;
	for(auto& [price, i, j] : land){
		if(vis[i].test(j) || vis[i].test(j + b - 1) || vis[i + a - 1].test(j) || vis[i + a - 1].test(j + b - 1)){
			continue;
		}
		ans.emplace_back(price, i, j);
		for(int _i = 0; _i < a; _i++){
			for(int _j = 0; _j < b; _j++){
				vis[i + _i].set(j + _j);
			}
		}
	}
	cout << ans.size() << "\n";
	for(auto& [v, i, j] : ans){
		cout << i << " " << j << " " << v << "\n";
	}
}