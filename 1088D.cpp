#include<bits/stdc++.h>
using namespace std;
int ask(int c, int d){
	cout << "? " << c << " " << d << endl;
	int x;
	cin >> x;
	return x;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a = 0, b = 0, c = 0, d = 0, previous = ask(0, 0);
	vector<int>p;
	for(int i = 29; i > -1; i--){
		int current = ask(c | (1 << i), d | (1 << i));
		if(current != previous){
			if(current > previous){
				b |= 1 << i;
				d |= 1 << i;
			}	
			else{
				a |= 1 << i;
				c |= 1 << i;
			}
			previous = ask(c, d);
		}
		else{
			p.emplace_back(i);
		}
	}
	for(int& i : p){
		if(ask(c | (1 << i), d) == -1){
			a |= 1 << i;
			b |= 1 << i;
		}
	}
	cout << "! " << a << " " << b;
}