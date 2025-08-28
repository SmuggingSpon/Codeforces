#include<bits/stdc++.h>
#define taskname "2071D1"
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
        int n;
        ll k;
        cin >> n >> k >> k;
        vector<int>pref(n + 1);
        pref[0] = 0;
        for(int i = 1; i <= n; i++){
            cin >> pref[i];
            pref[i] ^= pref[i - 1];
        }
        if(k <= n){
            cout << (pref[k] ^ pref[k - 1]) << "\n";
            continue;
        }
        int coef = 0;
        while(true){
            if((k >>= 1LL) > n){
                if(k == n + 1){
                    cout << (coef ^ pref[n] ^ pref[k >> 1]) << "\n";
                    break;
                }
                coef ^= pref[n];
                if(~n & 1){
                    coef ^= pref[(n + 1) >> 1];
                }
                if(k & 1LL){
                    cout << coef << "\n";
                    break;
                }
            }
            else{
                cout << (coef ^ pref[k]) << "\n";
                break;
            }
        }
    }
}