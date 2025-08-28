#include<bits/stdc++.h>
#define taskname "2047D"
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
		vector<int>a(n);
		for(int& x : a){
			cin >> x;
		}
		vector<int>p(n);
		iota(p.begin(), p.end(), 0);
		stable_sort(p.begin(), p.end(), [&] (int i, int j) -> bool{
			return a[i] < a[j];
		});
		int r = p[0];
		vector<bool>vis(n, false);
		vis[p[0]] = true;
		int max_value = INT_MAX;
		for(int i = 1; i < n; i++){
			if(a[p[i]] > max_value){
				break;
			}
			if(p[i] > r){
				vis[r = p[i]] = true;
			}
			else{
				minimize(max_value, a[p[i]] + 1);
			}
		}
		vector<int>b;
		for(int i = 0; i < n; i++){
			if(vis[i]){
				cout << a[i] << " ";
			}
			else{
				b.emplace_back(a[i]);
			}
		}
		sort(b.begin(), b.end());
		for(int& x : b){
			cout << x + 1 << " ";
		}
		cout << "\n";
	}
}