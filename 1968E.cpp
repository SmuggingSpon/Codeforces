#include<bits/stdc++.h>
#define taskname "1968E"
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
		if(n == 2){
			cout << "1 1\n1 2\n\n";
			continue;
		}
		for(int i = 3; i < n; i++){
			cout << "1 " << i << "\n";
		}
		cout << n << " " << n << "\n" << n << " " << n - 1 << "\n1 1\n\n";
	}
}