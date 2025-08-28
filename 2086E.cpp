#include<bits/stdc++.h>
#define taskname "2086E"
using namespace std;
typedef long long ll;
const ll INF = 1e18;
map<ll, ll>f[130];
vector<ll>number;
ll dp(int k, ll n){
    if(k == 0){
        return 1;
    }
    if(n == 0){
        return 0;
    }
    if(f[k].find(n) != f[k].end()){
        return f[k][n];
    }
    ll z = number[upper_bound(number.begin(), number.end(), n) - number.begin() - 1];
    return f[k][n] = dp(k - 1, n - z) + dp(k, z - 1);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    int _t;
    cin >> _t;
    number.emplace_back(1);
    while(number.back() < INF){
        number.emplace_back((number.back() << 2LL) + 1);
    }
    for(int _ = 0; _ < _t; _++){
        ll l, r, k;
        cin >> l >> r >> k;
        if(k > 129){
            cout << "0\n";
            continue;
        }
        cout << dp(k, r) - dp(k, l - 1) << "\n";
    }
}