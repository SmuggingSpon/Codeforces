#include<bits/stdc++.h>
#define taskname "2061E"
using namespace std;
typedef long long ll;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
int cnt_1[1 << 10];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	for(int i = 0; i < 1024; i++){
		cnt_1[i] = __builtin_popcount(i);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>b(n, vector<int>(m + 1, 1 << 30));
		ll ans = 0;
		for(int i = 0; i < n; i++){
			cin >> b[i][0];
			ans += b[i][0];
		}
		vector<int>value(1 << m, (1 << 30) - 1), B(m);
		for(int& x : B){
			cin >> x;
		}
		for(int mask = (1 << m) - 1; mask > 0; mask--){
			for(int i = 0; i < m; i++){
				if(1 << i & mask){
					value[mask] &= B[i];
				}
			}
		}
		vector<int>d;
		for(int i = 0; i < n; i++){
			for(int mask = (1 << m) - 1; mask > 0; mask--){
				minimize(b[i][cnt_1[mask]], b[i][0] & value[mask]);
			}
			for(int j = m; j > 0; j--){
				d.emplace_back(b[i][j - 1] - b[i][j]);
			}
		}
		sort(d.begin(), d.end(), greater<int>());
		for(int i = 0; i < k; i++){
			ans -= d[i];
		}
		cout << ans << "\n";
	}
}