#include<bits/stdc++.h>
#define taskname "1918B"
using namespace std;
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
		vector<int>a(n), b(n);
		for(int& x : a){
			cin >> x;
		}
		for(int& x : b){
			cin >> x;
		}
		vector<int>p(n);
		iota(p.begin(), p.end(), 0);
		sort(p.begin(), p.end(), [&] (int i, int j) -> bool{
			return a[i] < a[j];
		});
		for(int i = 1; i <= n; i++){
			cout << i << " ";
		}
		cout << "\n";
		for(int& x : p){
			cout << b[x] << " ";
		}
		cout << "\n";
	}
}