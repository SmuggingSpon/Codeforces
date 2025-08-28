#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int omul(int d){
	cout << "mul " << d << endl;
	int r;
	cin >> r;
	return r;
}
int odigit(){
	cout << "digit" << endl;
	int r;
	cin >> r;
	return r;	
}
int oadd(int d){
	cout << "add " << d << endl;
	int r;
	cin >> r;
	return r;
}
int oans(){
	cout << "!" << endl;
	int r;
	cin >> r;
	return r;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n;
		cin >> n;
		omul(999999999);
		odigit();
		if(n != 81){
			oadd(n - 81);
		}
		oans();
	}
}