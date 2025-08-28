#include<bits/stdc++.h>
#define taskname "2048D"
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
		int n, m, K;
		cin >> n >> m >> K;
		vector<int>a, b(m);
		for(int i = 1; i < n; i++){
			int x;
			cin >> x;
			if(x > K){
				a.emplace_back(x);
			}
		}
		sort(a.begin(), a.end());
		for(int& x : b){
			cin >> x;
		}
		sort(b.begin(), b.end());
		int start_delete = upper_bound(b.begin(), b.end(), K) - b.begin();
		for(int i = 1; i <= m; i++){
			int remain = m % i;
			ll ans = m / i;
			for(int j = start_delete + remain; j < m; j += i){
				ans += int(a.size()) - (lower_bound(a.begin(), a.end(), b[j]) - a.begin());
			}
			cout << ans << " ";
		}
		cout << "\n";
	}
}