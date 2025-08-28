#include<bits/stdc++.h>
#define taskname "2128B"
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
		deque<int>d;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			d.emplace_back(x);
		}
		cout << "LR";
		bool small = (d.front() < d.back());
		int last = d.back();
		d.pop_front();
		d.pop_back();
		while(!d.empty()){
			if(d.size() > 1){
				if(small){
					if(d.front() > last){
						cout << "L";
						last = d.front();
						d.pop_front();
					}
					else if(d.back() > last){
						cout << "R";
						last = d.back();
						d.pop_back();
					}
					else{
						cout << (d.front() > d.back() ? "RL" : "LR");
						last = max(d.front(), d.back());
						d.pop_front();
						d.pop_back();
					}
				}
				else{
					if(d.front() < last){
						cout << "L";
						last = d.front();
						d.pop_front();
					}
					else if(d.back() < last){
						cout << "R";
						last = d.back();
						d.pop_back();
					}
					else{
						cout << (d.front() < d.back() ? "RL" : "LR");
						last = min(d.front(), d.back());
						d.pop_front();
						d.pop_back();
					}
				}
				small = !small;
			}
			else{
				cout << "L";
				break;
			}
		}
		cout << "\n";
	}
}