#include<bits/stdc++.h>
#define taskname "2107C"
using namespace std;
typedef long long ll;
const ll INF = 1e18;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
ll kadane(vector<ll>a){
	ll ms = 0, ans = -INF, sum = 0;
	for(ll& x : a){
		maximize(ans, (sum += x) - ms);
		minimize(ms, sum);
	}
	return ans;
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
		ll k;
		string s;
		cin >> n >> k >> s;
		s += '0';
		vector<ll>a(n);
		for(ll& x : a){
			cin >> x;
		}
		vector<ll>current;
		ll val = -INF;
		for(int i = 0; i <= n; i++){
			if(s[i] == '1'){
				current.emplace_back(a[i]);
			}
			else{
				maximize(val, kadane(current));
				current.clear();
			}
		}
		if(val > k){
			cout << "No\n";
			continue;
		}
		int p = find(s.begin(), s.end(), '0') - s.begin();
		if(p == n && val != k){
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
		if(p < n){
			for(int i = p + 1; i < n; i++){
				if(s[i] == '0'){
					a[i] = -INF;
				}
			}
			ll left = 0, right = 0, sum = 0;
			for(int i = p - 1; i > -1 && s[i] == '1'; i--){
				maximize(left, sum += a[i]);
			}
			sum = 0;
			for(int i = p + 1; i < n && s[i] == '1'; i++){
				maximize(right, sum += a[i]);
			}
			a[p] = k - left - right;
		}
		for(ll& x : a){
			cout << x << " ";
		}
		cout << "\n";
	}
}