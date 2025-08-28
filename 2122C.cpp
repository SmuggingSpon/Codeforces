#include<bits/stdc++.h>
#define taskname "2122C"
using namespace std;
typedef long long ll;
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
		vector<int>x(n), y(n);
		for(int i = 0; i < n; i++){
			cin >> x[i] >> y[i];
		}
		vector<pair<int, int>>X, Y;
		for(int i = 0; i < n; i++){
			X.emplace_back(x[i], i);
			Y.emplace_back(y[i], i);
		}
		sort(X.begin(), X.end());
		sort(Y.begin(), Y.end());
		vector<deque<int>>d(2);
		for(int i = 0; i < n; i++){
			bool fx = (make_pair(x[i], i) >= X[n >> 1]), fy = (make_pair(y[i], i) >= Y[n >> 1]);
			if(fx == fy){
				if(fx){
					d[0].emplace_back(i);
				}
				else{
					d[0].emplace_front(i);
				}
			}
			else if(fx){
				d[1].emplace_back(i);
			}
			else{
				d[1].emplace_front(i);
			}
		}
		for(int i = 0; i < 2; i++){
			while(!d[i].empty()){
				cout << d[i].front() + 1 << " " << d[i].back() + 1 << "\n";
				d[i].pop_front();
				d[i].pop_back();
			}
		}
		cout << "\n";
	}
}