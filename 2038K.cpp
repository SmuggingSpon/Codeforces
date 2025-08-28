#include<bits/stdc++.h>
#define taskname "2038K"
using namespace std;
typedef long long ll;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
const ll INF = 1e18;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int n, a, b;
	cin >> n >> a >> b;
	vector<int>da, db;
	for(int i = 1; i * i <= a; i++){
		if(a % i == 0){
			da.emplace_back(i);
			if(i * i != a){
				da.emplace_back(a / i);
			}
		}
	}
	for(int i = 1; i * i <= b; i++){
		if(b % i == 0){
			db.emplace_back(i);
			if(i * i != b){
				db.emplace_back(b / i);
			}
		}
	}
	sort(da.begin(), da.end());
	sort(db.begin(), db.end());
	vector<int>last_a(da.size(), -1), last_b(db.size(), -1), pda(a + 1), pdb(b + 1);
	for(int i = 0; i < da.size(); i++){
		pda[da[i]] = i;
	}
	for(int i = 0; i < db.size(); i++){
		pdb[db[i]] = i;
	}
	for(int i = n; i > 0; i--){
		int x = __gcd(i, a);
		if(last_a[pda[x]] == -1){
			last_a[pda[x]] = i;
		}
		if(last_b[pdb[x = __gcd(i, b)]] == -1){
			last_b[pdb[x]] = i;
		}
	}
	if(last_a[0] == n && last_b[0] == n){
		return cout << (n << 2) - 2, 0;
	}
	vector<ll>dpb(db.size(), INF);
	dpb[0] = last_b[0] - 2;
	for(int i = 0; i < da.size(); i++){
		ll dpa = (i == 0 ? last_a[0] - 2 : INF);
		for(int j = 0; j < db.size(); j++){
			if((i != 0 || j != 0) && last_a[i] != -1 && last_b[j] != -1){
				ll current = min(dpa + 1LL * da[i] * last_b[j], dpb[j] + 1LL * db[j] * last_a[i]);
				if(last_a[i] == n && last_b[j] == n){
					for(int k = 1; k <= n; k++){
						current += __gcd(k, a) + __gcd(k, b);
					}
					return cout << current, 0;
				}
				else{
					minimize(dpa, current - 1LL * da[i] * last_b[j]);
					minimize(dpb[j], current - 1LL * db[j] * last_a[i]);
				}
			}
		}
	}
}