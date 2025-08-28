#include<bits/stdc++.h>
#define taskname "868F"
using namespace std;
typedef long long ll;
const int lim = 1e5 + 5;
const ll INF = 1e18;
template<class T>bool minimize(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}
ll val, dp[2][lim];
int L, R, cnt[lim], a[lim];
bool cur = true, pre = false;
void add(int x){
    val += cnt[x]++;
}
void remove(int x){
    val -= --cnt[x];
}
void solve(int l, int r, int opt_l, int opt_r){
    if(l > r){
        return;
    }
    int m = (l + r) >> 1, opt;
    dp[cur][m] = INF;
    while(R > m){
        remove(a[R--]);
    }
    while(R < m){
        add(a[++R]);
    }
    while(L < min(opt_r, m)){
        remove(a[L++]);
    }
    while(L > min(opt_r, m)){
        add(a[--L]);
    }
    for(int i = min(opt_r, m); i >= opt_l; add(a[--i]), L--){
        if(minimize(dp[cur][m], val + dp[pre][i - 1])){
            opt = i;
        }
    }
    solve(l, m - 1, opt_l, opt);
    solve(m + 1, r, opt, opt_r);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    memset(dp[cur], 0x0f, sizeof(dp[cur]));
    dp[cur][0] = 0;
    for(int _ = 0; _ < k; _++){
        swap(cur, pre);
        memset(cnt, R = val = 0, sizeof(cnt));
        solve(L = 1, n, 1, n);
    }
    cout << dp[cur][n];
}