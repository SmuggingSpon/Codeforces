#include<bits/stdc++.h>
#define taskname "1922C"
using namespace std;
typedef long long ll;
const int lim = 1e5 + 5;
ll l[lim], r[lim]; 
int a[lim];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = l[l[2] = 1] = 0; _ < _t; _++){
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 3; i <= n; i++){
			l[i] = l[i - 1] + (a[i] - a[i - 1] < a[i - 1] - a[i - 2] ? 1 : a[i] - a[i - 1]);
		}
		r[n] = 0;
		r[n - 1] = 1;
		for(int i = n - 2; i > 0; i--){
			r[i] = r[i + 1] + (a[i + 1] - a[i] < a[i + 2] - a[i + 1] ? 1 : a[i + 1] - a[i]);
		}
		int m;
		cin >> m;
		for(int _i = 0; _i < m; _i++){
			int x, y;
			cin >> x >> y;
			cout << (x < y ? l[y] - l[x] : r[y] - r[x]) << "\n";
		}
	}
}