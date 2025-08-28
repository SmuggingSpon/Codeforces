#include<bits/stdc++.h>
#define taskname "1920B"
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
		int n, k, x;
		cin >> n >> k >> x;
		vector<int>a(n + 1);
		a[0] = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		for(int i = 1; i <= n; i++){
			a[i] += a[i - 1];
		}
		int ans = -INT_MAX;
		for(int i = 0; i <= k; i++){
			maximize(ans, a[n] - (a[n] - a[n - i]) - ((a[n - i] - a[max(0, n - i - x)]) << 1));
		}
		cout << ans << "\n";
	}
}