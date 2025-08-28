#include<bits/stdc++.h>
#define taskname "2084D"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    int _t;
    cin >> _t;
    for(int _ = 0; _ < _t; _++){
        int n, m, k;
        cin >> n >> m >> k;
        if(n / (m + 1) >= k){
            int mex = n / (m + 1) - 1;
            for(int i = 1; i <= n; ){
                for(int j = 0; j <= mex && i <= n; j++, i++){
                    cout << j << " ";
                }
            }
        }
        else{
            set<int>s;
            for(int i = 1; i <= n; i++){
                s.insert(i);
            }
            vector<int>ans(n + 1);
            for(int i = 0; !s.empty(); i++){
                for(int j = m + 1, p = 1; j > 0; j--, p += k){
                    auto it = s.lower_bound(p);
                    if(it == s.end()){
                        break;
                    }
                    ans[p = *it] = i;
                    s.erase(it);
                }
            }
            for(int i = 1; i <= n; i++){
                cout << ans[i] << " ";
            }
        }
        cout << "\n";
    }
}