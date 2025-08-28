#include<bits/stdc++.h>
#define taskname "1325D"
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	ll u, v;
	cin >> u >> v;
	if(v < u || ((v -= u) & 1LL)){
		return cout << -1, 0;
	}
	v >>= 1LL;
	vector<ll>ans = {u, 0, 0};
	for(int i = 0; i < 59; i++){
		if(1LL << i & v){
			int cnt = 0;
			for(ll& x : ans){
				if((1LL << i & x) == 0){
					x |= 1LL << i;
					if(++cnt == 2){
						break;
					}
				}
			}
		}
	}
	sort(ans.begin(), ans.end(), greater<ll>());
	while(ans.back() == 0){
		ans.pop_back();
	}
	cout << ans.size() << "\n";
	for(ll& x : ans){
		cout << x << " ";
	}
}