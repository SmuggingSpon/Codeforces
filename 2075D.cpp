#include<bits/stdc++.h>
#define taskname "2075D"
using namespace std;
typedef long long ll;
const int INF = 1e9;
template<class T>void minimize(T& a, T b){
    if(a > b){
        a = b;
    }
}
int s[1 << 16], f[58][58];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    for(int mask = (1 << 16) - 1; mask > -1; mask--){
        s[mask] = 0;
        for(int i = 0; i < 16; i++){
            if(1 << i & mask){
                s[mask] += i + 1;
            }
        }
    }
    memset(f, 0x0f, sizeof(f));
    for(int mask = (1 << 16) - 1; mask > -1; mask--){
        if(s[mask] < 58){
            minimize(f[s[mask]][0], mask << 1);
            for(int init = ((1 << 16) - 1) ^ mask, _mask = init; _mask > 0; _mask = (_mask - 1) & init){
                if(s[_mask] < 58){
                    minimize(f[s[mask]][s[_mask]], (mask << 1) + (_mask << 1));
                }
            }
        }
    }
    int _t;
    cin >> _t;
    for(int _ = f[0][0] = 0; _ < _t; _++){
        ll x, y;
        cin >> x >> y;
        int ans = INF;
        for(int i = 0; i < 58; i++){
            for(int j = 0; j < 58; j++){
                if((x >> ll(i)) == (y >> ll(j))){
                    minimize(ans, min(f[i][j], f[j][i]));
                }
            }
        }
        cout << ans << "\n";
    }
}