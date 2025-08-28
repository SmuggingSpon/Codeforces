#include<bits/stdc++.h>
#define taskname "2065G"
using namespace std;
typedef long long ll;
const int lim = 2e5 + 5;
int n, lpf[lim];
vector<int>prime;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	memset(lpf, 0, sizeof(lpf));
	for(int i = 2; i < lim; i += 2){
		lpf[i] = 2;
	}
	prime.emplace_back(2);
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
	for(int _ = 0; _ < _t; _++){
		cin >> n;
		vector<int>cnt(n + 1, 0), cnt_2(n + 1, 0);
		ll ans = 0;
		int cnt_prime = 0;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			int sqr_x = int(sqrt(x));
			if(sqr_x * sqr_x == x){
				if(lpf[sqr_x] == sqr_x){
					ans += cnt[sqr_x] + cnt[x] + 1;
				}
			}
			else if(lpf[x] == x){
				ans += cnt_prime++ - cnt[x] + cnt_2[x];
				if(1LL * x * x <= n){
					ans += cnt[x * x];
				}
			}
			else{
				int y = x;
				vector<int>p;
				while(y > 1){
					if(!p.empty() && p.back() == lpf[y]){
						p.clear();
						break;
					}
					p.emplace_back(lpf[y]);
					y /= lpf[y];
				}
				if(p.size() == 2){
					ans += cnt[p[0]] + cnt[p[1]] + cnt[x] + 1;
					cnt_2[p[0]]++;
					cnt_2[p[1]]++;
				}
			}
			cnt[x]++;
		}
		cout << ans << "\n";
	}
}