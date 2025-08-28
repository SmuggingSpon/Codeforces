#include<bits/stdc++.h>
#define taskname "2070C"
using namespace std;
template<class T>void maximize(T& a, T b){
    if(a < b){
        a = b;
    }
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    int _t;
    cin >> _t;
    for(int _ = 0; _ < _t; _++){
        int n, k;
        string s;
        cin >> n >> k >> s;
        vector<int>a(n);
        for(int& x : a){
            cin >> x;
        }
        int low = 0, high = 1e9, ans;
        while(low <= high){
            int mid = (low + high) >> 1, cnt = 0;
            string t = "R";
            for(int i = 0; i < n; i++){
                if(a[i] > mid){
                    t += s[i];
                }
            }
            for(int i = 1; i < t.size(); i++){
                if(t[i] == 'B' && t[i - 1] == 'R'){
                    cnt++;
                }
            }
            if(cnt <= k){
                high = (ans = mid) - 1;
            }
            else{
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}