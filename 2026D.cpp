#include<bits/stdc++.h>
#define taskname "2026D"
using namespace std;
typedef long long ll;
const int lim = 3e5 + 5;
int n, q;
ll f_1[lim], f_2[lim], value[lim];
ll sum(int n){
	return (1LL * n * (n + 1)) >> 1LL;
}
ll solve(ll N){
	if(N == 0){
		return 0;
	}
	int low = 0, high = n, p;
	while(low <= high){
		int mid = (low + high) >> 1;
		if(sum(n) - sum(n - mid) <= N){
			low = (p = mid) + 1;
		}
		else{
			high = mid - 1;
		}
	}
	N -= sum(n) - sum(n - p);
	return value[p] + f_2[p + N] - f_2[p] - f_1[p] * N;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n;
	f_1[0] = f_2[0] = value[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> f_1[i];
		f_1[i] += f_1[i - 1];
	}
	for(int i = 1; i <= n; i++){
		f_2[i] = f_2[i - 1] + f_1[i];
	}
	for(int i = 0; i < n; i++){
		value[i + 1] = value[i] + f_2[n] - f_2[i] - f_1[i] * ll(n - i);
	}
	cin >> q;
	for(int _ = 0; _ < q; _++){
		ll l, r;
		cin >> l >> r;
		cout << solve(r) - solve(l - 1) << "\n";
	}
}