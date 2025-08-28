#include<bits/stdc++.h>
#define taskname "579A"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int x;
	cin >> x;
	cout << __builtin_popcount(x) << "\n";
}