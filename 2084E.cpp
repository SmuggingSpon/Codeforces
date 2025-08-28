#include<bits/stdc++.h>
#define taskname "2084E"
using namespace std;
template<class T>void minimize(T& a, T b){
    if(a > b){
        a = b;
    }
}
template<class T>void maximize(T& a, T b){
    if(a < b){
        a = b;
    }
}
const int mod = 1e9 + 7;
const int lim = 5005;
void add(int& a, int b){
    if((a += b) >= mod){
        a -= mod;
    }
}
int power(int a, int b){
    int ans = 1;
    for(; b > 0; b >>= 1, a = 1LL * a * a % mod){
        if(b & 1){
            ans = 1LL * ans * a % mod;
        }
    }
    return ans;
}
int gt[lim], inv_gt[lim];
int A(int k, int n){
    return k > n ? 0 : 1LL * gt[n] * inv_gt[n - k] % mod;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    for(int i = gt[0] = inv_gt[0] = inv_gt[1] = 1; i < lim; i++){
        gt[i] = 1LL * gt[i - 1] * i % mod;
    }
    inv_gt[lim - 1] = power(gt[lim - 1], mod - 2);
    for(int i = lim - 2; i > 1; i--){
        inv_gt[i] = 1LL * inv_gt[i + 1] * (i + 1) % mod;
    }
    int _t;
    cin >> _t;
    for(int _ = 0; _ < _t; _++){
        int n;
        cin >> n;
        vector<int>a(n + 1), f(n + 1), p(n, -1), cnt(n + 1, 0);
        f[0] = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            f[i] = f[i - 1] + int(a[i] == -1);
            if(a[i] != -1){
                p[a[i]] = i;
            }
            for(int j = 0; j < i; j++){
                cnt[f[i] - f[j]]++;
            }
        }
        int ans = 0;
        for(int i = 0, fix = 0, l = n + 1, r = -1; i < n; i++){
            if(p[i] != -1){
                int L = l, R = r;
                minimize(l, p[i] - 1);
                maximize(r, p[i]);
                if(R == -1){
                    fill(cnt.begin(), cnt.end(), 0);
                    for(int right = r; right <= n; right++){
                        for(int left = 0; left <= l; left++){
                            cnt[f[right] - f[left]]++;
                        }
                    }
                }
                else{
                    while(R < r){
                        for(int j = 0; j <= L; j++){
                            cnt[f[R] - f[j]]--;
                        }
                        R++;
                    }
                    while(L > l){
                        for(int j = R; j <= n; j++){
                            cnt[f[j] - f[L]]--;
                        }
                        L--;
                    }
                }
            }
            else{
                fix++;
            }
            for(int j = fix; j <= f[n]; j++){
                add(ans, 1LL * cnt[j] * A(fix, j) % mod * A(j - fix, f[n] - fix) % mod * gt[f[n] - j] % mod);
            }
        }
        cout << ans << "\n";
    }
}