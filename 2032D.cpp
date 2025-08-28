#include<bits/stdc++.h>
#define taskname "2032D"
using namespace std;
bool ask(int a, int b){
	cout << "? " << a << " " << b << endl;
	int r;
	cin >> r;
	return r == 1;
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
		vector<int>p(n, -1);
		vector<bool>is_root(n, true);
		p[1] = 0;
		for(int i = 2; i < n; i++){
			if(!ask(i, 1)){
				is_root[p[i] = 1] = false;
				break;
			}
			else{
				p[i] = 0;
			}
		}
		for(int i = 2; i < n; i++){
			if(p[i] == -1){
				for(int j = p[i - 1]; j < i; j++){
					if(is_root[j] && !ask(i, j)){
						is_root[p[i] = j] = false;
						break;
					}
				}
			}
		}
		cout << "! ";
		for(int i = 1; i < n; i++){
			cout << p[i] << " ";
		}
		cout << endl;
	}
}