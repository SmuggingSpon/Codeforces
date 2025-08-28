#include<bits/stdc++.h>
#define taskname "2029C"
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
		int n;
		cin >> n;
		vector<int>a(n);
		for(int& x : a){
			cin >> x;
		}
		int before = 0, after = 0, max_before = 0;
		for(int i = 0; i < n; i++){
			if(a[i] < before){
				before--;
			}
			else if(a[i] > before){
				before++;
			}
			if(a[i] < after){
				after--;
			}
			else if(a[i] > after){
				after++;
			}
			maximize(max_before, before);
			maximize(after, max_before);
		}
		cout << min(after, n - 1) << "\n";
	}
}