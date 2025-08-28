#include<bits/stdc++.h>
#define taskname "837F"
using namespace std;
typedef long long ll;
const int lim = 10;
int n;
ll k;
ll mul(ll a, ll b){
	return a == 0 || b == 0 ? 0 : (k / a < b ? k : a * b);
}
void add(ll& a, ll b){
	a = min(a + b, k);
}
struct Matrix{
	ll a[lim][lim];
	Matrix(){
		memset(a, 0, sizeof(a));
	}
	friend Matrix operator *(Matrix a, Matrix b){
		Matrix c;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				for(int k = 0; k < n; k++){
					add(c.a[i][j], mul(a.a[i][k], b.a[k][j]));
				}
			}
		}
		return c;
	}
	friend Matrix operator ^(Matrix a, ll b){
		Matrix ans = a;
		for(b--; b > 0; b >>= 1LL, a = a * a){
			if(b & 1LL){
				ans = ans * a;
			}
		}
		return ans;
	}
};
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n >> k;
	vector<ll>a(n);
	for(ll& x : a){
		cin >> x;
	}
	int p = 0;
	while(a[p] == 0){
		p++;
	}
	a.erase(a.begin(), a.begin() + p);
	n = a.size();
	if(*max_element(a.begin(), a.end()) >= k){
		return cout << 0, 0;
	}
	if(n > lim){
		int ans = 0;
		while(*max_element(a.begin(), a.end()) < k){
			ans++;
			for(int i = 1; i < n; i++){
				add(a[i], a[i - 1]);
			}
		}
		return cout << ans, 0;
	}
	Matrix init;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			init.a[i][j] = 1;
		}
	}
	ll low = 1, high = 1e18, ans;
	while(low <= high){
		ll mid = (low + high) >> 1LL, value = 0;
		Matrix coef = init ^ mid;
		for(int i = 0; i < n; i++){
			add(value, mul(a[i], coef.a[i][n - 1]));
		}
		if(value == k){
			high = (ans = mid) - 1;
		}
		else{
			low = mid + 1;
		}
	}
	cout << ans;
}