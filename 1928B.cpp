#include<bits/stdc++.h>
#define taskname "1928B"
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
		int n, ans = 0;
		cin >> n;
		vector<int>a(n);
		for(int& x : a){
			cin >> x;
		}
		sort(a.begin(), a.end());
		a.resize(unique(a.begin(), a.end()) - a.begin());
		for(int l = 0, r = 0; l < a.size(); l++){
			while(r < a.size() && a[r] - a[l] < n){
				r++;
			}
			maximize(ans, r - l);
		}
		cout << ans << "\n";
	}
}