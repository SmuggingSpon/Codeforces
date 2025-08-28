#include<bits/stdc++.h>
#define taskname "1853C"
using namespace std;
typedef long long ll;
const ll INF = 1e12;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    int _t;
    cin >> _t;
    for(int _ = 0; _ < _t; _++){
        int n, k;
        cin >> n >> k;
        vector<int>a(n);
        for(int& x : a){
            cin >> x;
        }
        ll ans = 1;
        for(int _ = 0, j = 0; _ < k; _++){
            while(j < n && a[j] <= ans + j){
                j++;
            }
            ans += j;
        }
        cout << ans << "\n";
    }  
}