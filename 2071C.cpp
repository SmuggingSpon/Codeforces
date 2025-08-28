#include<bits/stdc++.h>
#define taskname "2071C"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    int _t;
    cin >> _t;
    for(int _ = 0; _ < _t; _++){
        int n, st, en;
        cin >> n >> st >> en;
        vector<vector<int>>g(n + 1);
        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        vector<int>h(n + 1), parent(n + 1, 0);
        h[st] = 0;
        function<void(int)>dfs;
        dfs = [&] (int s){
            for(int& d : g[s]){
                if(d != parent[s]){
                    h[d] = h[parent[d] = s] + 1;
                    dfs(d);
                }
            }
        };
        dfs(st);
        vector<int>path;
        vector<bool>cnt(n + 1, false);
        while(en != st){
            path.emplace_back(en);
            cnt[en] = true;
            en = parent[en];
        }
        cnt[st] = true;
        path.emplace_back(st);
        vector<int>p(n);
        iota(p.begin(), p.end(), 1);
        sort(p.begin(), p.end(), [&] (int i, int j){
            return h[i] > h[j];
        });
        for(int& i : p){
            if(!cnt[i]){
                cout << i << " ";
            }
        }
        while(!path.empty()){
            cout << path.back() << " ";
            path.pop_back();
        }
        cout << "\n";
    }
}