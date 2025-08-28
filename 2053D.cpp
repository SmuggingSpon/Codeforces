#include<bits/stdc++.h>
#define taskname "2053D"
using namespace std;
const int mod = 998244353;
int power(int a, int b){
	int ans = 1;
	for(; b > 0; b >>= 1, a = 1LL * a * a % mod){
		if(b & 1){
			ans = 1LL * ans * a % mod;
		}
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
		int n, q, ans = 1;
		cin >> n >> q;
		vector<int>a(n + 1), b(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1; i <= n; i++){
			cin >> b[i];
		}
		vector<int>A = a, B = b;
		sort(A.begin() + 1, A.end());
		sort(B.begin() + 1, B.end());
		map<int, int>last_a, last_b;
		for(int i = 1; i <= n; i++){
			ans = 1LL * ans * min(A[last_a[A[i]] = last_b[B[i]] = i], B[i]) % mod;
		}
		cout << ans << " ";
		for(int _i = 0; _i < q; _i++){
			int o, x;
			cin >> o >> x;
			if(o == 1){
				int p = last_a[a[x]++]--;
				ans = 1LL * ans * power(min(A[p], B[p]), mod - 2) % mod;
				if(last_a[a[x]] == 0){
					last_a[a[x]] = p;
				}
				ans = 1LL * ans * min(++A[p], B[p]) % mod;
			}
			else{
				int p = last_b[b[x]++]--;
				ans = 1LL * ans * power(min(A[p], B[p]), mod - 2) % mod;
				if(last_b[b[x]] == 0){
					last_b[b[x]] = p;
				}
				ans = 1LL * ans * min(A[p], ++B[p]) % mod;
			}
			cout << ans << " ";
		}
		cout << "\n";
	}
}