#include<bits/stdc++.h>
#define taskname "55D"
using namespace std;
typedef long long ll;
const int pw_2[4] = {1, 2, 4, 8}, pw_3[3] = {1, 3, 9}, pw_5[2] = {1, 5}, pw_7[2] = {1, 7};
const int coef[10][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}, {0, 1, 0, 0}, {2, 0, 0, 0}, {0, 0, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 1}, {3, 0, 0, 0}, {0, 2, 0, 0}};
ll f[20][4][3][2][2][2520];
vector<int>d;
ll dp(int p, int s2, int s3, int s5, int s7, int mod, bool tight){
    if(p == d.size()){
        return mod % pw_2[s2] == 0 && mod % pw_3[s3] == 0 && mod % pw_5[s5] == 0 && mod % pw_7[s7] == 0;
    }
    if(tight){
        ll ans = dp(p + 1, max(s2, coef[d[p]][0]), max(s3, coef[d[p]][1]), max(s5, coef[d[p]][2]), max(s7, coef[d[p]][3]), ((mod << 3) + (mod << 1) + d[p]) % 2520, true);
        for(int i = 0; i < d[p]; i++){
            ans += dp(p + 1, max(s2, coef[i][0]), max(s3, coef[i][1]), max(s5, coef[i][2]), max(s7, coef[i][3]), ((mod << 3) + (mod << 1) + i) % 2520, false);
        }
        return ans;
    }
    ll& ans = f[p][s2][s3][s5][s7][mod];
    if(ans == -1){
        for(int i = ans = 0; i < 10; i++){
            ans += dp(p + 1, max(s2, coef[i][0]), max(s3, coef[i][1]), max(s5, coef[i][2]), max(s7, coef[i][3]), ((mod << 3) + (mod << 1) + i) % 2520, false);
        }
    }
    return ans;
}
ll solve(ll n){
    d.clear();
    while(n > 0){
        d.emplace_back(n % 10);
        n /= 10;
    }
    while(d.size() < 20){
        d.emplace_back(0);
    }
    reverse(d.begin(), d.end());
    return dp(0, 0, 0, 0, 0, 0, true);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    memset(f, -1, sizeof(f));
    int _t;
    cin >> _t;
    for(int _ = 0; _ < _t; _++){
        ll l, r;
        cin >> l >> r;
        cout << solve(r) - solve(l - 1) << "\n";
    }
}
