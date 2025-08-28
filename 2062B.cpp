#include<bits/stdc++.h>
#define taskname "2062B"
using namespace std;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
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
		bool ans = true;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			if(i - ((x - 1) >> 1) > 0 || i + ((x - 1) >> 1) < n - 1){
				ans = false;
			}
		}
		cout << (ans ? "YES\n" : "NO\n");
	}
}