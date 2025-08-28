#include<bits/stdc++.h>
#define taskname "2024C"
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
		for(int i = 0; i < n; i++){
			cin >> a[i] >> b[i];
		}
		vector<int>p(n);
		iota(p.begin(), p.end(), 0);
		sort(p.begin(), p.end(), [&] (int i, int j) -> bool{
			return a[i] + b[i] < a[j] + b[j] || (a[i] + b[i] == a[j] + b[j] && a[i] < a[j]);
		});
		for(int& i : p){
			cout << a[i] << " " << b[i] << " ";
		}
		cout << "\n";
	}
}