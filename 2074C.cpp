#include<bits/stdc++.h>
#define taskname "2074C"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    int _t;
    cin >> _t;
    for(int _ = 0; _ < _t; _++){
        int x;
        cin >> x;
        int cnt = __builtin_popcount(x);
        if(cnt == 1 || (1 << cnt) - 1 == x){
            cout << "-1\n";
            continue;
        }
        int s0 = -1, s1 = -1;
        for(int i = 0; s0 == -1 || s1 == -1; i++){
            if(1 << i & x){
                s1 = i;
            }
            else{
                s0 = i;
            }
        }
        cout << ((1 << s0) | (1 << s1)) << "\n";
    }
}