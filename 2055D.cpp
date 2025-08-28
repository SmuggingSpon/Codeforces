#include<bits/stdc++.h>
#define taskname "2055D"
using namespace std;
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
void solve(){
	int n, k, l;
	cin >> n >> k >> l;
	k <<= 1;
	l <<= 1;
	vector<int>a(n);
	for(int& x : a){
		cin >> x;
		x <<= 1;
	}
	int t = 0, p = 0;
	for(int i = 0; i < n; i++){
		if(p >= l){
			return void(cout << t << "\n");
		}
		if(a[i] - t > p){
			if(i == 0){
				t += a[i];
				p = k;
			}
			else{
				int time = (a[i] - p - t) >> 1;
				if(p + time + k >= l){
					return void(cout << t + min(time, l - p) << "\n");
				}
				t += time;
				p += time + k;
			}
		}
		else if(a[i] > p){
			p += k;
		}
		else{
			maximize(p, a[i] + k + min(t, p - a[i]));
		}
	}
	cout << t + max(0, l - p) << "\n";
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		solve();
	}
}