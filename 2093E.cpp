#include<bits/stdc++.h>
#define taskname "2093E"
using namespace std;
template<class T>void minimize(T& a, T b){
    if(a > b){
        a = b;
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
        int n, k;
        cin >> n >> k;
        vector<int>a(n);
        for(int& x : a){
            cin >> x;
            minimize(x, n + 3);
        }
        int low = 1, high = n + 2, ans = 0;
        while(low <= high){
            int mid = (low + high) >> 1, cnt = 0;
            vector<bool>vis(n + 5, false);
            for(int i = 0, j = 0; i < n; ){
                int mex = 0;
                while(i < n && mex < mid){
                    vis[a[i++]] = true;
                    while(vis[mex]){
                        mex++;
                    }
                }
                if(mex < mid){
                    break;
                }
                cnt++;
                while(j < i){
                    vis[a[j++]] = false;
                }
            }
            if(cnt >= k){
                low = (ans = mid) + 1;
            }
            else{
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}