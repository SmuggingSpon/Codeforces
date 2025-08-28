#include<bits/stdc++.h>
#define taskname "2024B"
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
		int n, k;
		cin >> n >> k;
		vector<int>a(n);
		for(int& x : a){
			cin >> x;
		}
		a.emplace_back(0);
		sort(a.begin(), a.end());
		ll ans = 0;
		for(int i = 1; i <= n; i++){
			int x = a[i] - a[i - 1];
			if(k <= 1LL * (n - i + 1) * x){
				ans += k;
				break;
			}
			else{
				k -= (n - i + 1) * x;
				ans += 1LL * (n - i + 1) * x + 1;
			}
		}
		cout << ans << "\n";
	}
}