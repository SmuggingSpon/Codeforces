#include<bits/stdc++.h>
#define taskname "1968C"
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
		vector<int>x(n - 1);
		for(int& v : x){
			cin >> v;
		}
		cout << "501 ";
		for(int i = 1, sum = 501; i < n; i++){
			cout << (sum += x[i - 1]) << " ";
		}
		cout << "\n";
	}
}