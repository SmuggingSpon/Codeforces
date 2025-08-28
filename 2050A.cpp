#include<bits/stdc++.h>
#define taskname "2050A"
using namespace std;
int main(){
    if(fopen(taskname".inp", "r")){
        freopen(taskname".inp", "r", stdin);
    }
    int _t;
    cin >> _t;
    for(int _ = 0; _ < _t; _++){
        int n, m, sum_length = 0;
        cin >> n >> m;
        int ans = n;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            if((sum_length += s.size()) > m){
                ans = i;
                sum_length = -1000000;
            }
        }
        cout << ans << "\n";
    }
}