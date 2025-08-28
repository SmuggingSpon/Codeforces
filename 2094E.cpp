#include<bits/stdc++.h>
#define taskname "2094E"
using namespace std;
typedef long long ll;
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
int cnt[30][2];
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
		memset(cnt, 0, sizeof(cnt));
		vector<int>a(n);
		for(int& x : a){
			cin >> x;
			for(int j = 0; j < 30; j++){
				cnt[j][x >> j & 1]++;
			}
		}
		ll ans = 0;
		for(int& x : a){
			ll sum = 0;
			for(int j = 0; j < 30; j++){
				sum += 1LL * cnt[j][(x >> j & 1) ^ 1] * (1 << j);
			}
			maximize(ans, sum);
		}
		cout << ans << "\n";
	}
}