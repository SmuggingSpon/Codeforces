#include<bits/stdc++.h>
#define taskname "2085D"
using namespace std;
typedef long long ll;
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
        vector<int>d(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> d[i];
        }
        vector<bool>cnt(n + 1, false);
        for(int i = n - k; i > 0; i -= k + 1){
            cnt[i] = true;
        }
        priority_queue<int>pq;
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            pq.push(d[i]);
            if(cnt[i]){
                ans += pq.top();
                pq.pop();
            }
        }
        cout << ans << "\n";
    }
}