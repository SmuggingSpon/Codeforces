#include<bits/stdc++.h>
#define taskname "2032C"
using namespace std;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
const int lim = 2e5 + 5;
int a[lim];
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
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		int ans = n;
		for(int i = 0, j = 1; i + 1 < n; i++){
			int sum = a[i + 1] + a[i + 2];
			while(j <= n && a[j] < sum){
				j++;
			}
			minimize(ans, i + n - j + 1);
		}
		cout << ans << "\n";
	}
}