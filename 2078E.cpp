#include<bits/stdc++.h>
using namespace std;
int ask(int n){
    cout << n << endl;
    int x;
    cin >> x;
    return x;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _t, pat_even = 0;
    cin >> _t;
    for(int i = 0; i < 30; i += 2){
        pat_even |= 1 << i;
    }
    for(int _ = 0; _ < _t; _++){
        vector<int>cnt(30, 0);
        int sum = ask(0), even = ask(pat_even), d = even - sum;
        for(int i = 0; i < 30; i++){
            if(1 << i & d){
                if(i & 1){
                    cnt[i - 1] = 2;
                }
                else{
                    cnt[i] = 1;
                }
            }
        }
        int even_sum = 0;
        for(int i = 0; i < 30; i += 2){
            even_sum += (2 - cnt[i]) * (1 << i);
        }
        for(int i = 1; i < 30; i += 2){
            cnt[i] = 2;
        }
        d = sum - even_sum;
        for(int i = 0; i < 31; i++){
            if(1 << i & d){
                if(i & 1){
                    cnt[i] = 1;
                }
                else{
                    cnt[i - 1] = 0;
                }
            }
        }
        int m, ans = 0;
        cout << "!" << endl;
        cin >> m;
        for(int i = 0; i < 30; i++){
            if(1 << i & m){
                ans += 1 << (i + 1);
            }
            else{
                ans += (2 - cnt[i]) * (1 << i);
            }
        }
        cout << ans << endl;
    }
}