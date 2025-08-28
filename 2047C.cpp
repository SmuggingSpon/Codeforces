#include<bits/stdc++.h>
#define taskname "2047C"
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
		int n, ans = -INT_MAX;
		cin >> n;
		vector<int>a(n), b(n);
		for(int& x : a){
			cin >> x;
		}
		for(int& x : b){
			cin >> x;
		}
		for(int i = 0; i < n; i++){
			int current_ans = a[i] + b[i];
			for(int j = 0; j < n; j++){
				if(i != j){
					current_ans += max(a[j], b[j]);
				}
			}
			maximize(ans, current_ans);
		}
		cout << ans << "\n";
	}
}