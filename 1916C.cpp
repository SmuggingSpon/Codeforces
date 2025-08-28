#include<bits/stdc++.h>
#define taskname "1916C"
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
		vector<int>a(n + 1), type(2, 0);
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		ll sum = 0;
		for(int i = 1; i <= n; i++){
			type[a[i] & 1]++;
			sum += a[i];
			cout << sum - type[1] / 3 - int((type[1] > 1 || type[0] > 0) && type[1] % 3 == 1) << " ";
		}
		cout << "\n";
	}
}