#include<bits/stdc++.h>
#define taskname "1853B"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    int _t;
    cin >> _t;
    for(int _ = 0; _ < _t; _++){
        int n, k, ans = 0;
        cin >> n >> k;
        for(int i = 0, prev = n; i <= n; i++){
            for(int j = prev; j >= i + int(i == 0); j--){
                int a = i, b = j;
                for(int _ = 2; _ < k; _++){
                    int c = a + b;
                    a = b;
                    if((b = c) > n){
                        break;
                    }
                }
                prev--;
                if(b <= n){
                    ans += int(b == n);
                    prev += int(b < n);
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
}