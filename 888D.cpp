#include<bits/stdc++.h>
#define taskname "888D"
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int n, k;
	cin >> n >> k;
	ll ans = 1;
	if(k > 1){
		ans += (1LL * n * (n - 1)) >> 1LL;
	}
	if(k > 2){
		ans += (1LL * n * (n - 1) * (n - 2)) / 3LL;
	}
	if(k > 3){
		ans += (3LL * n * (n - 1) * (n - 2) * (n - 3)) / 8LL;
	}
	cout << ans;
}