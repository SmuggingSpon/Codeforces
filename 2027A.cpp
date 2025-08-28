#include<bits/stdc++.h>
#define taskname "2027A"
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
		int n, H = 0, W = 0;
		cin >> n;
		for(int i = 1; i <= n; i++){
			int h, w;
			cin >> h >> w;
			maximize(H, h);
			maximize(W, w);
		}
		cout << ((H + W) << 1) << "\n";
	}
}