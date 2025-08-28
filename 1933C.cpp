#include<bits/stdc++.h>
#define taskname "1933C"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int a, b, l;
		cin >> a >> b >> l;
		map<int, bool>cnt;
		while(true){
			int L = l;
			while(true){
				cnt[L] = true;
				if(L % b != 0){
					break;
				}
				L /= b;
			}
			if(l % a != 0){
				break;
			}
			l /= a;
		}
		cout << cnt.size() << "\n";
	}
}