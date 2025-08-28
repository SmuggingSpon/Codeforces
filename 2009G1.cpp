#include<bits/stdc++.h>
#define taskname "2009G1"
using namespace std;
const int lim = 2e5 + 5;
int a[lim], cnt[lim << 1];
multiset<int>s;
void add(int i){
	s.insert(++cnt[i]);
	if(cnt[i] > 1){
		s.erase(s.find(cnt[i] - 1));
	}
}
void sub(int i){
	s.erase(s.find(cnt[i]));
	if(--cnt[i] > 0){
		s.insert(cnt[i]);
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, k, q;
		cin >> n >> k >> q;
		s.clear();
		fill(cnt, cnt + (n << 1) + 1, 0);
		vector<int>a(n + 1), ans(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			add(a[i] + n - i);
			if(i >= k){
				ans[i - k + 1] = *s.rbegin();
				sub(a[i - k + 1] + n - (i - k + 1));
			}
		}
		for(int _i = 0; _i < q; _i++){
			int l, r;
			cin >> l >> r;
			cout << k - ans[l] << "\n";
		}
	}
}