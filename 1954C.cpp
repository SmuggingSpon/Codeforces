#include<bits/stdc++.h>
#define taskname "1954C"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		string x, y;
		cin >> x >> y;
		bool need_same = true;
		for(int i = 0; i < x.size(); i++){
			if(need_same){
				if(x[i] != y[i]){
					if(x[i] < y[i]){
						swap(x[i], y[i]);
					}
					need_same = false;
				}
			}
			else{
				if(x[i] > y[i]){
					swap(x[i], y[i]);
				}
			}
		}
		cout << x << "\n" << y << "\n";
	}
}