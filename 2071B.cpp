#include<bits/stdc++.h>
#define taskname "2071B"
using namespace std;
typedef long long ll;
bool is_square(ll x){
    ll t = sqrtl(x);
    return t * t == x;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    int _t;
    cin >> _t;
    for(int _ = 0; _ < _t; _++){
        int n;
        cin >> n;
        if(is_square((1LL * n * (n + 1)) >> 1LL)){
            cout << "-1\n";
            continue;
        }        
        ll sum = 0;
        for(int i = 1; i <= n; i++){
            if(is_square(sum += i)){
                cout << i + 1 << " " << i << " ";
                sum += ++i;
            }
            else{
                cout << i << " ";
            }
        }
        cout << "\n";
    }
}