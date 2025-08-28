#include<bits/stdc++.h>
#define taskname "2104B"
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
		vector<int>a(n + 1), left_max(n + 1);
		left_max[0] = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			left_max[i] = max(left_max[i - 1], a[i]);
		}
		ll sum = 0;
		for(int i = 1; i <= n; i++){
			cout << (sum += a[n - i + 1]) + max(0, left_max[n - i] - a[n - i + 1]) << " ";
		}
		cout << "\n";
	}
}