#include<bits/stdc++.h>
#define taskname "2074D"
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
        int n, m;
        cin >> n >> m;
        vector<int>x(n), r(n);
        for(int& i : x){
            cin >> i;
        }
        for(int& i : r){
            cin >> i;
        }
        vector<map<int, int>>cnt(m + 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= r[i]; j++){
                int left = sqrt(1LL * r[i] * r[i] - 1LL * j * j);
                cnt[j][x[i] - left]++;
                cnt[j][x[i] + left + 1]--;
            }
        }
        ll ans = 0;
        for(int i = 0; i <= m; i++){
            int pre, sum = 0;
            for(auto& [u, v] : cnt[i]){
                if(sum > 0){
                    ans += (u - pre) << (int(i > 0));
                }
                sum += v;
                pre = u;
            }
        }
        cout << ans << "\n";
    }
}