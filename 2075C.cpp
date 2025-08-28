#include<bits/stdc++.h>
#define taskname "2075C"
using namespace std;
typedef long long ll;
const int lim = 2e5 + 5;
ll bit_sum[lim];
int n, m, a[lim], bit_cnt[lim];
void update(int p, int x){
    for(; p <= n; p += p & -p){
        bit_sum[p] += x;
        bit_cnt[p]++;
    }
}
pair<ll, int>get(int p){
    pair<ll, int>ans = make_pair(0LL, 0);
    for(; p > 0; p -= p & -p){
        ans.first += bit_sum[p];
        ans.second += bit_cnt[p];
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
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
            cin >> a[i];
            if(a[i] == n){
                a[i]--;
            }
        }
        for(int i = 1; i <= n; i++){
            bit_sum[i] = bit_cnt[i] = 0;
        }
        sort(a + 1, a + m + 1);
        ll ans = 0;
        for(int i = 1; i <= m; i++){
            pair<ll, int>R = get(n), L = get(n - a[i] - 1);
            ll sum = R.first - L.first;
            int cnt = R.second - L.second;
            ans += (1LL * cnt * a[i] + sum) << 1LL;
            update(a[i], a[i] + 1 - n);
        }
        cout << ans << "\n";
    }
}