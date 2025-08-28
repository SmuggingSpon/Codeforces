#include<bits/stdc++.h>
#define taskname "2019B"
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
		int n, q;
		cin >> n >> q;
		vector<int>x(n);
		for(int& p : x){
			cin >> p;
		}
		map<ll, ll>ans;
		for(int i = 0; i < n; i++){
			ans[1LL * (i + 1) * (n - i) - 1]++;
		}
		for(int i = 1; i < n; i++){
			ans[1LL * i * (n - i)] += x[i] - x[i - 1] - 1;
		}
		for(int _ = 0; _ < q; _++){
			ll k;
			cin >> k;
			cout << ans[k] << " ";
		}
		cout << "\n";
	}
}