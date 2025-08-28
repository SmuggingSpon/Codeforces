#include<bits/stdc++.h>
#define taskname "2085E"
using namespace std;
typedef long long ll;
const int INF = 1e9;
const int LIM = 1e6 + 1;
int cnt[LIM];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    memset(cnt, 0, sizeof(cnt));
    int _t;
    cin >> _t;
    for(int _ = 0; _ < _t; _++){
        int n;
        cin >> n;
        vector<int>a(n), b(n);
        for(int& x : a){
            cin >> x;
        }
        for(int& x : b){
            cin >> x;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a == b){
            cout << INF << "\n";
            continue;
        }
        ll sum = abs(accumulate(a.begin(), a.end(), 0LL) - accumulate(b.begin(), b.end(), 0LL));
        vector<int>candidate;
        for(int i = 1; 1LL * i * i <= sum; i++){
            if(sum % i == 0){
                candidate.emplace_back(i);
                if(sum / i < LIM){
                    candidate.emplace_back(sum / i);
                }
            }
        }
        int ans = -1;
        for(int& k : candidate){
            for(int& x : b){
                cnt[x]++;
            }
            bool flag = true;
            for(int& x : a){
                if(cnt[x % k]-- == 0){
                    flag = false;
                    cnt[x % k] = 0;
                    break;
                }
            }
            for(int& x : b){
                cnt[x] = 0;
            }
            if(flag){
                ans = k;
                break;
            }
        }
        cout << ans << "\n";
    }
}