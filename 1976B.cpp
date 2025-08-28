#include<bits/stdc++.h>
#define taskname "1976B"
using namespace std;
typedef long long ll;
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
		vector<int>a(n), b(n + 1);
		for(int& x : a){
			cin >> x;
		}
		for(int& x : b){
			cin >> x;
		}
		vector<pair<int, int>>range;
		ll ans = 0;
		for(int i = 0; i < n; i++){
			if(a[i] > b[i]){
				swap(a[i], b[i]);
			}
			range.emplace_back(a[i], b[i]);
			ans += b[i] - a[i];
		}
		int add = INT_MAX;
		for(auto& [u, v] : range){
			if(u <= b[n] && v >= b[n]){
				add = 0;
				break;
			}
			minimize(add, min(abs(b[n] - u), abs(b[n] - v)));
		}
		cout << ans + add + 1 << "\n";
	}
}