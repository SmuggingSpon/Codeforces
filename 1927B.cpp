#include<bits/stdc++.h>
#define taskname "1927B"
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
		vector<queue<int>>p(n + 1);
		string s(n, '@');
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			p[x].push(i);
		}
		char current = 'a';
		while(!p[0].empty()){
			for(int i = 0; i <= n; i++){
				if(p[i].empty()){
					break;
				}
				s[p[i].front()] = current;
				p[i].pop();
			}
			current++;
		}
		cout << s << "\n";
	}
}