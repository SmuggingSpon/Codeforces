#include<bits/stdc++.h>
#define taskname "255D"
using namespace std;
typedef long long ll;
ll f(int n){
	return (1LL * n * (n + 1)) >> 1LL;
}
ll calc(int bound_1, int bound_2, int cnt){
	int start = min(bound_1, cnt), keep = max(1, min(bound_2, cnt - bound_1 + 1));
	return 1LL * start * keep + f(start - 1) - f(start - min(bound_2, cnt) + keep - 1);	
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int n, x, y;
	ll c;
	cin >> n >> x >> y >> c;
	if(c == 1){
		return cout << 0, 0;
	}
	int low = 1, high = n << 1, ans;
	while(low <= high){
		int mid = low + ((high - low) >> 1);
		if(calc(x - 1, y, mid) + calc(n - x + 1, y, mid + 1) + calc(x - 1, n - y, mid - 1) + calc(n - x + 1, n - y, mid) >= c){
			high = (ans = mid) - 1;
		}
		else{
			low = mid + 1;
		}
	}
	cout << ans;
}