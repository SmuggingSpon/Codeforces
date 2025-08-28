#include<bits/stdc++.h>
#define taskname "1975C"
using namespace std;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
const int lim = 2e5 + 5;
int a[lim], f[lim];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = f[0] = 0; _ < _t; _++){
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		int low = 0, high = 1e9, ans;
		while(low <= high){
			int mid = (low + high) >> 1;
			bool can = false;
			for(int i = 1; i <= n; i++){
				f[i] = f[i - 1] + (a[i] < mid ? -1 : 1);
			}
			for(int i = 2, current = 0; i <= n; i++){
				if(f[i] > current){
					can = true;
					break;
				}
				minimize(current, f[i - 1]);
			}
			if(can){
				low = (ans = mid) + 1;
			}
			else{
				high = mid - 1;
			}
		}
		cout << ans << "\n";
	}
}