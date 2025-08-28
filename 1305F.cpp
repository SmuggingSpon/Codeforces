#include<bits/stdc++.h>
#define taskname "1305F"
using namespace std;
typedef long long ll;
const ll INF = 1e18;
template<class T>void minimize(T& a, T b){
    if(a > b){
        a = b;
    }
}
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int get_random(int l, int r){
    return uniform_int_distribution<int>(l, r)(rng);
}
const int lim = 1e6 + 5;
vector<int>prime(1, 2);
bitset<lim>cnt;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    cnt.set();
    for(int i = 3; i * i < lim; i += 2){
        if(cnt.test(i)){
            for(int j = i * i; j < lim; j += i << 1){
                cnt.reset(j);
            }
        }
    }
    for(int i = 3; i < lim; i += 2){
        if(cnt.test(i)){
            prime.emplace_back(i);
        }
    }
    int n;
    cin >> n;
    vector<ll>a(n);
    for(ll& x : a){
        cin >> x;
    }
    vector<ll>candidate;
    for(int _ = 0; _ < 50; _++){
        int i = get_random(0, n - 1);
        for(int j = -1; j < 2; j++){
            ll d = a[i] + j;
            for(int& k : prime){
                if(1LL * k * k > d){
                    break;
                }
                if(d % k == 0){
                    candidate.emplace_back(k);
                    d /= k;
                    while(d % k == 0){
                        d /= k;
                    }
                }
            }
            if(d > 1){
                candidate.emplace_back(d);
            }
        }
    }
    sort(candidate.begin(), candidate.end());
    candidate.resize(unique(candidate.begin(), candidate.end()) - candidate.begin());
    ll ans = INF;
    for(ll& d : candidate){
        ll cnt = 0;
        for(ll& x : a){
            ll r = x % d;
            cnt += (x == r ? d - r : min(r, d - r));
        }
        minimize(ans, cnt);
    }
    cout << ans;
}