#include<bits/stdc++.h>
#define taskname "1974C"
using namespace std;
typedef long long ll;
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
		map<tuple<int, int, int>, int>cnt;
		ll ans = 0;
		for(int i = 2; i < n; i++){
			ans -= 3 * cnt[make_tuple(a[i - 2], a[i - 1], a[i])]++;
		}
		map<pair<int, int>, int>count;
		for(int i = 2; i < n; i++){
			ans += count[make_pair(a[i - 2], a[i - 1])]++;
		}
		count.clear();
		for(int i = 2; i < n; i++){
			ans += count[make_pair(a[i - 2], a[i])]++;
		}
		count.clear();
		for(int i = 2; i < n; i++){
			ans += count[make_pair(a[i - 1], a[i])]++;
		}
		cout << ans << "\n";
	}
}