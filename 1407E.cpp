#include<bits/stdc++.h>
#define taskname "1407E"
using namespace std;
const int lim = 5e5 + 5;
vector<int>rg[lim], g[lim][2];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        g[u][c].emplace_back(v);
        rg[v].emplace_back(u);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 2; j++){
            sort(g[i][j].begin(), g[i][j].end());
            g[i][j].resize(unique(g[i][j].begin(), g[i][j].end()) - g[i][j].begin());
        }
    }
    queue<int>q;
    q.push(n);
    vector<int>color(n + 1, -1);
    vector<bool>vis(n + 1, false);
    color[n] = 0;
    vis[n] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int& v : rg[u]){
            bool flag_0 = binary_search(g[v][0].begin(), g[v][0].end(), u), flag_1 = binary_search(g[v][1].begin(), g[v][1].end(), u);
            if(color[v] == -1 || color[v] == 2){
                if(flag_0 && flag_1){
                    color[v] = 2;
                    if(!vis[v]){
                        q.push(v);
                        vis[v] = true;
                    }
                }
                else if(flag_0){
                    color[v] = 1;
                }
                else if(flag_1){
                    color[v] = 0;
                }
                else{
                    color[v] = 2;
                }
            }
            else if(((color[v] == 0 && flag_0) || (color[v] == 1 && flag_1)) && !vis[v]){
                q.push(v);
                vis[v] = true;
            }
        }
    }
    vector<int>dp(n + 1, -1);
    dp[1] = 0;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(color[u] != -1){
            for(int& v : g[u][color[u] & 1]){
                if(dp[v] == -1){
                    dp[v] = dp[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    cout << dp[n] << "\n";
    for(int i = 1; i <= n; i++){
        cout << (abs(color[i]) & 1);
    }
}