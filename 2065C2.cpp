#include<bits/stdc++.h>
#define taskname "2065C2"
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
		int n, m;
		cin >> n >> m;
		vector<int>a(n), b(m);
		for(int& x : a){
			cin >> x;
		}
		for(int& x : b){
			cin >> x;
		}
		sort(b.begin(), b.end());
		minimize(a[0], b[0] - a[0]);
		bool ans = true;
		for(int i = 1; i < n; i++){
			auto it = lower_bound(b.begin(), b.end(), a[i - 1] + a[i]);
			if(it != b.end()){
				if(a[i] < a[i - 1]){
					a[i] = *it - a[i];
				}
				else{
					minimize(a[i], *it - a[i]);
				}
			}
			else if(a[i] < a[i - 1]){
				ans = false;
				break;
			}
		}
		cout << (ans ? "YES\n" : "NO\n");
	}
}