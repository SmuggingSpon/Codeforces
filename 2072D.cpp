#include<bits/stdc++.h>
#define taskname "2072D"
using namespace std;
template<class T>bool minimize(T& a, T b){
	if(a > b){
		a = b;
		return true;
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, L = 1, R = 1, opt = 0;
		cin >> n;
		vector<int>a(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1; i < n; i++){
			for(int j = i + 1, add = 0; j <= n; j++){
				if(a[j] < a[i]){
					add--;
				}
				else if(a[j] > a[i]){
					add++;
				}
				if(minimize(opt, add)){
					L = i;
					R = j;
				}
			}
		}
		cout << L << " " << R << "\n";
	}
}