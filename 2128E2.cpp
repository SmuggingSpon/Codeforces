#include<bits/stdc++.h>
#define taskname "2128E2"
using namespace std;
const int lim = 3e5 + 5;
int n, k, bit[lim], a[lim];
void update(int p, int x){
	for(; p <= n; p += p & -p){
		bit[p] += x;
	}
}
int get(int p){
	int ans = 0;
	for(; p > 0; p -= p & -p){
		ans += bit[p];
	}
	return ans;
}
tuple<int, int, int>get_max_med(){	
	int low = 1, high = n, ans, lans, rans;
	while(low <= high){
		int mid = (low + high) >> 1;
		vector<int>pref(n + 1);
		pref[0] = 0;
		for(int i = 1; i <= n; i++){
			pref[i] = pref[i - 1] + (a[i] >= mid ? 1 : -1);
		}
		bool flag = false;
		for(int i = k, j = 0; i <= n; i++){
			if(pref[i] >= pref[j]){
				lans = j + 1;
				rans = i;
				flag = true;
				break;
			}
			if(pref[i - k + 1] < pref[j]){
				j = i - k + 1;
			}
		}
		if(flag){
			low = (ans = mid) + 1;
		}
		else{
			high = mid - 1;
		}
	}
	return make_tuple(ans, lans, rans);
}
pair<int, int>get_med(){
	int low = 0, high = n, N = get(n), L = 0, R;
	while(low <= high){
		int mid = (low + high) >> 1;
		if(get(mid) < ((N + 1) >> 1)){
			low = L = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	low = 0;
	high = n;
	while(low <= high){
		int mid = (low + high) >> 1;
		if(get(mid) < (N >> 1) + 1){
			low = R = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	return make_pair(L, R);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		cin >> n >> k;
		set<int>s;
		for(int i = 1; i <= n; s.insert(i++)){
			cin >> a[i];
			bit[i] = 0;
		}	
		auto [ma, l, r] = get_max_med();
		for(int i = 1; i <= n; i++){
			a[i] = n + 1 - a[i];
		}
		auto [mi, lmi, rmi] = get_max_med();
		for(int i = 1; i <= n; i++){
			a[i] = n + 1 - a[i];
		}
		for(int i = l; i <= r; i++){
			update(a[i], 1);
		}
		vector<tuple<int, int, int>>ans;
		auto work = [&] (){
			auto [L, R] = get_med();
			for(auto it = s.lower_bound(L); it != s.end() && *it <= R; it = next(it)){
				ans.emplace_back(*it, l, r);
			}
			s.erase(s.lower_bound(L), s.upper_bound(R));
		};
		work();
		while(l > lmi){
			update(a[--l], 1);
			work();
		}
		while(r < rmi){
			update(a[++r], 1);
			work();
		}
		while(l < lmi){
			update(a[l++], -1);
			work();
		}
		while(r > rmi){
			update(a[r--], -1);
			work();
		}
		cout << ans.size() << "\n";
		for(auto& [med, L, R] : ans){
			cout << med << " " << L << " " << R << "\n";
		}
	}
}