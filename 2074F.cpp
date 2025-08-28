#include<bits/stdc++.h>
#define taskname "2074F"
using namespace std;
typedef long long ll;
int get(int l, int r){
    int small;
    for(int i = 0; i < 20; i++){
        if(1 << i & r){
            small = i;
            break;
        }
    }
    for(int i = small; i > 0; i--){
        if(r - (1 << i) >= l){
            return i;
        }
    }
    return 0;
}
ll get(int l, int r, int b){
    int ans = 0;
    for(; r > l; ){
        int i = get(l, r);
        ans += 1 << abs(i - b);
        r -= 1 << i;
    }
    return ans;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    int _t;
    cin >> _t;
    for(int _ = 0; _ < _t; _++){
        int l1, r1, l2, r2;
        ll ans = 0;
        cin >> l1 >> r1 >> l2 >> r2;
        while(r1 > l1 && r2 > l2){
            int b1 = get(l1, r1), b2 = get(l2, r2);
            if(b1 < b2){
                r1 -= 1 << b1;
                ans += get(l2, r2, b1);
            }
            else{
                r2 -= 1 << b2;
                ans += get(l1, r1, b2);
            }
        }
        cout << ans << "\n";
    }
}