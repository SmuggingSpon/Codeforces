#include<bits/stdc++.h>
#define taskname "1936A"
using namespace std;
char ask(int a, int b, int c, int d){
	cout << "? " << a << " " << b << " " << c << " " << d << endl;
	char cmp;
	cin >> cmp;
	return cmp;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, max_index = 0, opt_index = 0;
		cin >> n;
		for(int i = 1; i < n; i++){
			if(ask(max_index, max_index, i, i) == '<'){
				max_index = i;
			} 
		}
		vector<int>index(1, 0);
		for(int i = 1; i < n; i++){
			char ans = ask(max_index, opt_index, max_index, i);
			if(ans == '<'){
				index.clear();
				index.emplace_back(opt_index = i);
			}
			else if(ans == '='){
				index.emplace_back(i);
			}
		}
		for(int& x : index){
			if(ask(x, x, opt_index, opt_index) == '<'){
				opt_index = x;
			}		
		}
		cout << "! " << opt_index << " " << max_index << endl;
	}
}