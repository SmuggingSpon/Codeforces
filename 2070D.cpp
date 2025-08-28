#include<bits/stdc++.h>
#define taskname "2070D"
using namespace std;
const int mod = 998244353;
void add(int& a, int b){
    if((a += b) >= mod){
        a -= mod;
    }
}
void sub(int& a, int b){
    if((a -= b) < 0){
        a += mod;
    }
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
        cin >> n;
        vector<int>parent(n + 1), h(n + 1);
        h[1] = 0;
        vector<vector<int>>g(n + 1);
        for(int i = 2; i <= n; i++){
            cin >> parent[i];
            g[parent[i]].emplace_back(i);
            h[i] = h[parent[i]] + 1;
        }
        vector<int>p(n);
        iota(p.begin(), p.end(), 1);
        sort(p.begin(), p.end(), [&] (int i, int j){
            return h[i] > h[j];
        });
        vector<int>dp(n + 1, 1), sum_dp(n + 2, 0);
        for(int& u : p){
            for(int& v : g[u]){
                sub(dp[u], dp[v]);
            }
            add(dp[u], sum_dp[h[u] + 1]);
            add(sum_dp[h[u]], dp[u]);
        }
        int ans = 1;
        for(int& i : g[1]){
            add(ans, dp[i]);
        }
        cout << ans << "\n";
    }
}