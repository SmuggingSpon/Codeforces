#include<bits/stdc++.h>
#define taskname "2050B"
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
		vector<ll>sum(2, 0);
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			sum[i & 1] += x;
		}
		cout << (sum[0] % ((n + 1) >> 1) == 0 && sum[1] % (n >> 1) == 0 && sum[0] / ((n + 1) >> 1) == sum[1] / (n >> 1) ? "YES\n" : "NO\n");
	}
}