#include<bits/stdc++.h>
#define taskname "1781D"
using namespace std;
typedef long long ll;
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
bool is_square(ll x){
	ll i = sqrtl(x);
	return i * i == x;
}
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
		vector<int>a(n);
		for(int& x : a){
			cin >> x;
		}
		sort(a.begin(), a.end());
		vector<ll>candidate;
		for(int i = 1; i < n; i++){
			for(int j = 0; j < i; j++){
				int x = a[i] - a[j];
				for(int d = 1; d * d <= x; d++){
					if(x % d == 0){
						int dd = x / d;
						if(~(d ^ dd) & 1){
							int p = (d + dd) >> 1;
							candidate.emplace_back(1LL * p * p - a[i]);
						}
					}
				}
			}
		}
		sort(candidate.begin(), candidate.end());
		candidate.resize(unique(candidate.begin(), candidate.end()) - candidate.begin());
		int ans = 1;
		for(ll& x : candidate){
			if(x < 0){
				continue;
			}
			int cnt = 0;
			for(int& i : a){
				if(is_square(x + i)){
					cnt++;
				}
			}
			maximize(ans, cnt);
		}
		cout << ans << "\n";
	}
}