#include<bits/stdc++.h>
#define taskname "1943B"
using namespace std;
typedef long long ll;
const int lim = 2e5 + 5;
const int mod = 2e9 + 33;
const int base = 397;
int n, q, p[lim], id[lim];
struct Hash{
	int value[lim];
	Hash(){
		value[0] = 0;
	}
	void build(const string s){
		for(int i = 1; i < s.size(); i++){
			value[i] = (1LL * value[i - 1] * base + s[i]) % mod;
		}
	}
	int get_hash(int l, int r){
		return (ll(value[r]) - 1LL * value[l - 1] * p[r - l + 1] + 1LL * mod * mod) % mod;
	}
};
Hash init, after;
bool is_palindrome(int l, int r){
	return init.get_hash(l, r) == after.get_hash(n - r + 1, n - l + 1);
}
ll sum_2(int l, int r){
	if((l & 1) != (r & 1)){
		r--;
	}
	return (1LL * (r + l) * (r - l + 2)) >> 2LL;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	for(int i = p[0] = 1; i < lim; i++){
		p[i] = 1LL * p[i - 1] * base % mod;
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		string s;
		cin >> n >> q >> s;
		char prev_character = '#';
		for(int i = 0, ID = 0; i < n; i++){
			if(s[i] != prev_character){
				prev_character = s[i];
				ID++;
			}
			id[++i] = ID;
		}
		prev_character = '#';
		for(int i = 1, ID = 0; i < n; i++){
			if(s[i] != prev_character){
				prev_character = s[i];
				ID++;
			}
			id[++i] = ID;
		}
		init.build('#' + s);
		reverse(s.begin(), s.end());
		after.build('#' + s);
		reverse(s.begin(), s.end());
		for(int _i = 0; _i < q; _i++){
			int l, r;
			cin >> l >> r;
			ll ans = (is_palindrome(l, r) ? 0 : r - l + 1);
			bool odd = false, even = false;
			if(r - l > 1){
				if(id[l] != id[r - int((l & 1) != (r & 1))]){
					odd = true;
					ans += sum_2(3, r - l);
				}
				if(id[l + 1] != id[r - int((l & 1) == (r & 1))]){
					even = true;
					if(!odd){
						ans += sum_2(3, r - l);
					}
				}
				if(odd || even || s[l - 1] != s[l]){
					ans += sum_2(2, r - l);
				}
			}
			cout << ans << "\n";
		}	
	}
}