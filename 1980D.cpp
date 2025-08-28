#include<bits/stdc++.h>
#define taskname "1980D"
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
		vector<int>a(n);
		for(int& x : a){
			cin >> x;
		}
		vector<int>b(n - 1);
		for(int i = 1; i < n; i++){
			b[i - 1] = __gcd(a[i - 1], a[i]);
		}
		int left_index = n - 2, right_index = 0;
		for(int i = 1; i + 1 < n; i++){
			if(b[i] < b[i - 1]){
				left_index = i - 1;
				break;
			}
		}
		for(int i = n - 3; i > -1; i--){
			if(b[i] > b[i + 1]){
				right_index = i + 1;
				break;
			}
		}
		if(right_index < 2 || left_index > n - 4){
			cout << "YES\n";
			continue;
		}
		bool ans = false;
		for(int i = 1; i + 1 < n; i++){
			if(left_index > i - 3 && right_index < i + 2 && (i == 1 || b[i - 2] <= __gcd(a[i - 1], a[i + 1])) && (i == n - 2 || __gcd(a[i - 1], a[i + 1]) <= b[i + 1])){
				ans = true;
				break;
			}
		}
		cout << (ans ? "YES\n" : "NO\n");
	}
}