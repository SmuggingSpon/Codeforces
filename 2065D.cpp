#include<bits/stdc++.h>
#define taskname "2065D"
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>a(n, vector<int>(m));
		vector<ll>sum(n, 0);
		for(int i = 0; i < n; i++){
			for(int& x : a[i]){
				cin >> x;
				sum[i] += x;
			}
		}
		vector<int>p(n);
		iota(p.begin(), p.end(), 0);
		sort(p.begin(), p.end(), [&] (int i, int j) -> bool{
			return sum[i] < sum[j];
		});
		ll ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				ans += 1LL * (m - j) * a[p[i]][j];
			}
			ans += 1LL * i * m * sum[p[i]];
		}
		cout << ans << "\n";
	}
}