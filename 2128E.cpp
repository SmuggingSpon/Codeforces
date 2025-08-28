#include<bits/stdc++.h>
#define taskname "2128E"
using namespace std;
template<class T>bool minimize(T& a, T b){
	if(a > b){
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
		int n, k;
		cin >> n >> k;
		vector<int>a(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		int low = 1, high = n, ans, l, r;
		while(low <= high){
			int mid = (low + high) >> 1;
			vector<int>f(n + 1);
			f[0] = 0;
			for(int i = 1; i <= n; i++){
				f[i] = f[i - 1] + (mid <= a[i] ? 1 : -1);
			}
			for(int i = k, j = 0; i <= n; i++){
				if(f[i] - f[j] > -1){
					l = j + (f[0] = 1);
					r = i;
					break;
				}	
				if(f[i - k + 1] < f[j]){
					j = i - k + 1;
				}
			}
			if(f[0] == 1){
				low = (ans = mid) + 1;
			}
			else{
				high = mid - 1;
			}
		}
		cout << ans << " " << l << " " << r << "\n";
	}
}