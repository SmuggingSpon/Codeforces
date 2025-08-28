#include<bits/stdc++.h>
#define taskname "1986G2"
using namespace std;
typedef long long ll;
const int lim = 5e5 + 1;
vector<int>d[lim], cnt[lim];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	for(int i = 1; i < lim; i++){
		for(int j = i; j < lim; j += i){
			d[j].emplace_back(i);
		}
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, cnt_other = 0;
		cin >> n;
		ll ans = 0;
		vector<pair<int, int>>value;
		for(int i = 1; i <= n; i++){
			int a, b = i;
			cin >> a;
			if(a % b == 0){
				ans--;
			}
			cnt[i].clear();
			int g = __gcd(a, b);
			value.emplace_back(a /= g, b /= g);
			for(int& divisor : d[a]){
				cnt[b].emplace_back(divisor);
			}
		}
		for(int i = 1; i <= n; i++){
			sort(cnt[i].begin(), cnt[i].end());
		}
		for(auto& [ai, bi] : value){
			for(int& bj : d[ai]){
				ans += upper_bound(cnt[bj].begin(), cnt[bj].end(), bi) - lower_bound(cnt[bj].begin(), cnt[bj].end(), bi);
			}
		}
		cout << (ans >> 1LL) << "\n";
	}
}