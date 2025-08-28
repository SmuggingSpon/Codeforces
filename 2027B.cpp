#include<bits/stdc++.h>
#define taskname "2027B"
using namespace std;
template<class T>void minimize(T& a, T b){
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
		int n;
		cin >> n;
		vector<int>a(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		int ans = n;
		for(int i = 1; i <= n; i++){
			int cnt = i - 1;
			for(int j = i + 1; j <= n; j++){
				if(a[i] < a[j]){
					cnt++;
				}
			}
			minimize(ans, cnt);
		}
		cout << ans << "\n";
	}
}