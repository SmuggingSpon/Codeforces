#include<bits/stdc++.h>
#define taskname "2033F"
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		ll n;
		int k;
		cin >> n >> k;
		if(k == 1){
			cout << n % mod << "\n";
			continue;
		}
		int a = 1, b = 1, cycle_length = 2;
		vector<int>p;
		while(true){
			if(b == 0){
				p.emplace_back(cycle_length);
			}
			int c = a + b;
			a = b;
			if((b = c % k) == 1 && a == 1){
				cycle_length--;
				break;
			}
			cycle_length++;
		}
		cout << (((n - 1) / ll(p.size())) % mod * ll(cycle_length) % mod + p[(n - 1) % int(p.size())]) % mod << "\n";
	}
}