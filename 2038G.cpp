#include<bits/stdc++.h>
#define taskname "2038G"
using namespace std;
int ask(string s){
	cout << "1 " << s << endl;
	int x;
	cin >> x;
	return x;
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
		int cnt_0 = ask("0");
		if(cnt_0 == 0){
			cout << "0 1 1" << endl;
		}
		else if(cnt_0 == n){
			cout << "0 1 0" << endl;
		}
		else if(cnt_0 - ask("00") == ask("01")){
			cout << "0 " << n << " 1" << endl;
		}
		else{
			cout << "0 " << n << " 0" << endl;
		}
		cin >> cnt_0;
	}
}