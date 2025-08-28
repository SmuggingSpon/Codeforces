#include<bits/stdc++.h>
#define taskname "1349A"
using namespace std;
typedef long long ll;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
const int lim = 2e5 + 5;
int n, lpf[lim];
vector<int>prime, cnt[lim];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	memset(lpf, 0, sizeof(lpf));
	for(int i = 2; i < lim; i += 2){
		lpf[i] = 2;
	}
	for(int i = 3; i < lim; i += 2){
		if(lpf[i] == 0){
			prime.emplace_back(lpf[i] = i);
		}
		for(int& j : prime){
			int T = i * j;
			if(T >= lim || (lpf[T] = j) == lpf[i]){
				break;
			}
		}
	}
	prime.emplace_back(2);
	cin >> n;
	for(int _ = 0; _ < n; _++){
		int x;
		cin >> x;
		while(x > 1){
			int p = lpf[x], e = 0;
			while(lpf[x] == p){
				x /= p;
				e++;
			}
			cnt[p].emplace_back(e);
		}
	}
	ll ans = 1;
	for(int& i : prime){
		if(cnt[i].size() > n - 2){
			sort(cnt[i].begin(), cnt[i].end());
			if(cnt[i].size() == n - 1){
				for(int j = 0; j < cnt[i][0]; j++){
					ans *= ll(i);
				}
			}
			else{
				for(int j = 0; j < cnt[i][1]; j++){
					ans *= ll(i);
				}
			}
		}
	}
	cout << ans;
}