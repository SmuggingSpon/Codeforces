#include<bits/stdc++.h>
#define taskname "2029E"
using namespace std;
const int LIM = 4e5 + 5;
int lpf[LIM];
vector<int>prime;
void solve(){
	int n;
	cin >> n;
	vector<int>a(n);
	for(int& x : a){
		cin >> x;
	}
	sort(a.begin(), a.end());
	for(int i = 1; i < n; i++){
		if(lpf[a[i]] == a[i]){
			return void(cout << "-1\n");
		}
	}
	if(lpf[a[0]] != a[0]){
		return void(cout << "2\n");
	}
	for(int i = 1; i < n; i++){
		if(a[i] - lpf[a[i]] < (a[0] << 1) && a[i] != (a[0] << 1)){
			return void(cout << "-1\n");
		}
	}
	cout << a[0] << "\n";
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	memset(lpf, 0, sizeof(lpf));
	for(int i = 2; i < LIM; i += 2){
		lpf[i] = 2;
	}
	for(int i = 3; i < LIM; i += 2){
		if(lpf[i] == 0){
			prime.emplace_back(lpf[i] = i);
		}
		for(int& j : prime){
			int T = i * j;
			if(T >= LIM || (lpf[T] = j) == lpf[i]){
				break;
			}
		}
	}
	for(int _ = 0; _ < _t; _++){
		solve();
	}
}