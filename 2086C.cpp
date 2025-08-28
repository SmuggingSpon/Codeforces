#include<bits/stdc++.h>
#define taskname "2086C"
using namespace std;
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
        vector<int>p(n + 1), id(n + 1, -1), size(n + 1, 0);
        for(int i = 1; i <= n; i++){
            cin >> p[i];
        }
        for(int i = 1; i <= n; i++){
            if(id[i] == -1){
                int ID = i, x = i;
                while(id[x] == -1){
                    size[id[x] = ID]++;
                    x = p[x];
                }
            }
        }
        vector<bool>vis(n + 1, false);
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            if(!vis[id[x]]){
                vis[id[x]] = true;
                ans += size[id[x]];
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
}