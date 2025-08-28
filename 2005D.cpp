#include<bits/stdc++.h>
#define taskname "2005D"
using namespace std;
typedef long long ll;
template<class T>bool maximize(T& a, T b){
	if(a < b){
		a = b;
		return true;
	}
	return false;
}
const int lim = 2e5 + 5;
int n, pref_a, pref_b, suf_a[lim], suf_b[lim], log_v[lim], a[lim][18], b[lim][18];
int get_a(int l, int r){
	if(l > r){
		return 0;
	}
	int k = log_v[r - l + 1];
	return __gcd(a[l][k], a[r - (1 << k) + 1][k]);
}
int get_b(int l, int r){
	if(l > r){
		return 0;
	}
	int k = log_v[r - l + 1];
	return __gcd(b[l][k], b[r - (1 << k) + 1][k]);
}
int get(int l, int r){
	return __gcd(__gcd(pref_a, suf_a[r + 1]), get_b(l, r)) + __gcd(__gcd(pref_b, suf_b[r + 1]), get_a(l, r));
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	log_v[0] = -1;
	for(int i = 1; i < lim; i++){
		log_v[i] = log_v[i >> 1] + 1;
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i][0];
		}
		for(int i = 1; i <= n; i++){
			cin >> b[i][0];
		}
		for(int j = 1; j < 18; j++){
			for(int i = 1; i + (1 << j) - 1 <= n; i++){
				a[i][j] = __gcd(a[i][j - 1], a[i + (1 << (j - 1))][j - 1]);
				b[i][j] = __gcd(b[i][j - 1], b[i + (1 << (j - 1))][j - 1]);
			}
		}
		int ans_max = 0, pre_g = suf_a[n] = a[n][suf_a[n + 1] = suf_b[n + 1] = 0];
		ll ans_cnt = 0;
		vector<int>suf(1, n);
		while(true){
			int low = 1, high = suf.back(), p;
			while(low <= high){
				int mid = (low + high) >> 1;
				if(get_a(mid, n) == pre_g){
					high = (p = mid) - 1;
				}
				else{
					low = mid + 1;
				}
			}
			if(p == 1){
				break;
			}
			suf.emplace_back(--p);
			pre_g = get_a(p, n);
		}
		suf.emplace_back(n);
		pre_g = suf_b[n] = b[n][pref_a = pref_b = 0];
		while(true){
			int low = 1, high = suf.back(), p;
			while(low <= high){
				int mid = (low + high) >> 1;
				if(get_b(mid, n) == pre_g){
					high = (p = mid) - 1;
				}
				else{
					low = mid + 1;
				}
			}
			if(p == 1){
				break;
			}
			suf.emplace_back(--p);
			pre_g = get_b(p, n);
		}
		suf.emplace_back(1);
		sort(suf.begin(), suf.end());
		suf.resize(unique(suf.begin(), suf.end()) - suf.begin());
		reverse(suf.begin(), suf.end());	
		for(int i = n - 1; i > 0; i--){
			suf_a[i] = __gcd(suf_a[i + 1], a[i][0]);
			suf_b[i] = __gcd(suf_b[i + 1], b[i][0]);
		}
		for(int l = 1; l <= n; l++){
			if(suf.back() < l){
				suf.pop_back();
			}
			vector<int>index = suf;
			index.emplace_back(l);
			pre_g = a[l][0];
			while(true){
				int low = index.back() + 1, high = n, p = index.back();
				while(low <= high){
					int mid = (low + high) >> 1;
					if(get_a(l, mid) == pre_g){
						low = (p = mid) + 1;
					}
					else{
						high = mid - 1;
					}
				} 
				if(p == n){
					break;
				}
				index.emplace_back(++p);
				pre_g = get_a(l, p);
			}
			index.emplace_back(l);
			pre_g = b[l][0];
			while(true){
				int low = index.back() + 1, high = n, p = index.back();
				while(low <= high){
					int mid = (low + high) >> 1;
					if(get_b(l, mid) == pre_g){
						low = (p = mid) + 1;
					}
					else{
						high = mid - 1;
					}
				} 
				if(p == n){
					break;
				}
				index.emplace_back(++p);
				pre_g = get_b(l, p);
			}
			sort(index.begin(), index.end());
			index.resize(unique(index.begin(), index.end()) - index.begin());
			index.emplace_back(n + 1);
			for(int i = 0; i + 1 < index.size(); i++){
				int value = get(l, index[i]);
				if(maximize(ans_max, value)){
					ans_cnt = 0;
				}
				if(ans_max == value){
					ans_cnt += index[i + 1] - index[i];
				}
			}
			pref_a = __gcd(pref_a, a[l][0]);
			pref_b = __gcd(pref_b, b[l][0]);
		}
		cout << ans_max << " " << ans_cnt << "\n";
	}
}