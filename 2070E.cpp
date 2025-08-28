#include<bits/stdc++.h>
#define taskname "2070E"
using namespace std;
typedef long long ll;
const int lim = 1e6 + 5;
const int LIM = lim << 1;
int bit[LIM];
void update(int p){
    for(p += lim; p < LIM; p += p & -p){
        bit[p]++;
    }
}
int get(int p){
    int ans = 0;
    for(p += lim; p > 0; p -= p & -p){
        ans += bit[p];
    }
    return ans;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    int n;
    string s;
    cin >> n >> s;
    memset(bit, 0, sizeof(bit));
    update(0);
    ll ans = 0;
    map<int, int>cnt;
    cnt[0] = 1;
    for(int i = 0, f = 0; i < n; i++){
        if(s[i] == '0'){
            f++;
        }
        else{
            f -= 3;
        }
        ans += get(f + 1) - cnt[f]++ - cnt[f - 1];
        update(f);
    }
    cout << ans;
}