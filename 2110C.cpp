#include<bits/stdc++.h>
#define taskname "2110C"
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int>d(n + 1), l(n + 1), r(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> d[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> l[i] >> r[i];
	}
	vector<int>pos;
	for(int i = 1, ll = 0, rr = 0; i <= n; i++){
		if(d[i] == -1){
			pos.emplace_back(i);
			rr++;
		}
		else{
			ll += d[i];
			rr += d[i];
		}
		if(ll > r[i] || rr < l[i]){
			return void(cout << "-1\n");
		}
		while(ll < l[i]){
			d[pos.back()] = 1;
			pos.pop_back();
			ll++;
		}
		while(rr > r[i]){
			d[pos.back()] = 0;
			pos.pop_back();
			rr--;
		}
	}
	for(int& i : pos){
		d[i] = 0;
	}
	for(int i = 1; i <= n; i++){
		cout << d[i] << " ";
	}
	cout << "\n";
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