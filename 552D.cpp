#include<bits/stdc++.h>
#define taskname "552D"
using namespace std;
typedef long long ll;
const int INF = 1e9;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    int n;
    cin >> n;
    vector<pair<int, int>>a(n);
    for(auto& [x, y] : a){
        cin >> x >> y;
    }
    vector<vector<int>>cnt;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            pair<int, int>N = make_pair(a[i].second - a[j].second, a[j].first - a[i].first);
            int A = N.first, B = N.second, C = -A * a[i].first - B * a[i].second, g = max(1, __gcd(__gcd(abs(A), abs(B)), abs(C)));
            if(A < 0 || (A == 0 && B < 0)){
                A = -A;
                B = -B;
                C = -C;
            }
            cnt.emplace_back(vector<int>{A / g, B / g, C / g});
        }
    }
    sort(cnt.begin(), cnt.end());
    cnt.emplace_back(vector<int>(3, INF));
    ll ans = 1LL * n * (n - 1) * (n - 2) / 6LL;
    int current = 1;
    for(int i = 1; i < cnt.size(); i++){
        if(cnt[i] != cnt[i - 1]){
            for(int j = 1; j <= n; j++){
                if(((j * (j - 1)) >> 1) == current){
                    ans -= 1LL * j * (j - 1) * (j - 2) / 6LL;
                    break;
                }
            }
            current = 0;
        }
        current++;
    }
    cout << ans;
}