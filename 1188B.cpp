#include<bits/stdc++.h>
#define taskname "1188B"
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int n, p, k;
	cin >> n >> p >> k;
	auto square = [&] (int x){
		return 1LL * x * x % p;	
	};
	map<int, int>cnt;
	ll ans = 0;
	for(int _ = 0; _ < n; _++){
		int x;
		cin >> x;
		ans += cnt[(square(square(x)) - 1LL * k * x % p + p) % p]++;
	}
	cout << ans;
}