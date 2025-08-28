#include<bits/stdc++.h>
#define taskname "2078C"
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
        cin >> n;
        vector<int>b(n << 1);
        for(int& x : b){
            cin >> x;
        }
        sort(b.begin(), b.end());
        ll sum = 0;
        for(int i = 0; i + 1 < (n << 1); i++){
            if(i & 1){
                sum += b[i];
            }
            else{
                sum -= b[i];
            }
        }
        cout << b[(n << 1) - 1] << " " << ll(b[(n << 1) - 1] - sum);
        for(int i = 0; i + 1 < (n << 1); i++){
            cout << " " << b[i];
        }
        cout << "\n";
    }
}