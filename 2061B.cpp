#include<bits/stdc++.h>
#define taskname "2061B"
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int>a(n);
	for(int& x : a){
		cin >> x;
	}
	sort(a.begin(), a.end(), greater<int>());
	for(int i = 1; i < n; i++){
		if(a[i] == a[i - 1]){
			vector<int>b;
			for(int j = 0; j < n; j++){
				if(j != i && j != i - 1){
					b.emplace_back(a[j]);
				}
			}
			for(int k = 1; k < b.size(); k++){
				if(b[k - 1] - b[k] < (a[i] << 1)){
					return void(cout << a[i] << " " << a[i] << " " << b[k - 1]  << " " << b[k] << "\n");
				}
			}
			return void(cout << "-1\n");
		}
	}
	cout << "-1\n";
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