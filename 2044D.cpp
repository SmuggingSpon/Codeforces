#include<bits/stdc++.h>
#define taskname "2044D"
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
		set<int>s;
		for(int i = 1; i <= n; i++){
			s.insert(i);
		}
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			if(s.find(x) == s.end()){
				cout << *s.begin() << " ";
				s.erase(s.begin());
			}
			else{
				cout << x << " ";
				s.erase(x);
			}
		}
		cout << "\n";
	}
}