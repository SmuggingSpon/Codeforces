#include<bits/stdc++.h>
#define taskname "1978C"
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
		ll k;
		cin >> n >> k;
		if(k & 1LL){
			cout << "NO\n";
			continue;
		}
		vector<int>a(n + 1);
		for(int l = 1, r = n; l <= r; l++, r--){
			while(l < r && (abs(l - r) << 1) > k){
				a[l] = l;
				l++;
			}
			if(l == r){
				a[r] = r;
				break;
			}
			k -= abs(l - r) << 1;
			a[a[r] = l] = r;
		}
		if(k > 0){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for(int i = 1; i <= n; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
	}
}