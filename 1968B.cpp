#include<bits/stdc++.h>
#define taskname "1968B"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, m;
		string a, b;
		cin >> n >> m >> a >> b;
		a += '2';
		for(int i = 0, j = 0; i <= n; i++, j++){
			while(j < m && b[j] != a[i]){
				j++;
			}
			if(j == m){
				cout << i << "\n";
				break;
			}
		}
	}
}