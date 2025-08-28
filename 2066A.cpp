#include<bits/stdc++.h>
#define taskname "2066A"
using namespace std;
int ask(int i, int j){
	cout << "? " << i << " " << j << endl;
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
		vector<int>x(n);
		vector<bool>cnt(n + 1, false);
		for(int& i : x){
			cin >> i;
			cnt[i] = true;
		}
		bool have_empty = false;
		for(int i = 1; i <= n; i++){
			if(!cnt[i]){
				have_empty = true;
				int a = ask(i, int(i == 1) + 1), b = ask(int(i == 1) + 1, i);
				cout << (a == 0 || b == 0 ? "! A" : "! B") << endl;
				break;
			}
		}
		if(!have_empty){
			int i = find(x.begin(), x.end(), 1) - x.begin() + 1, j = find(x.begin(), x.end(), n) - x.begin() + 1, a = ask(i, j), b = ask(j, i);
			cout << (a == b && a >= n - 1 ? "! B" : "! A") << endl;
		}
	}
}