#include<bits/stdc++.h>
#define taskname "1082E"
using namespace std;
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
const int lim = 5e5 + 5;
int a[lim], cnt[lim], p[lim], value[lim];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int n, c;
	cin >> n >> c;
	memset(p, cnt[0] = 0, sizeof(p));
	memset(value, -0x0f, sizeof(value));
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		cnt[i] = cnt[i - 1] + int(a[i] == c);
	}
	int ans = cnt[n];
	for(int i = 1; i <= n; i++){
		int N = cnt[n] - cnt[i];
		maximize(value[a[i]], cnt[i - 1] - p[a[i]]);
		maximize(ans, ++p[a[i]] + N + value[a[i]]);
	}
	cout << ans;
}