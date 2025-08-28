#include<bits/stdc++.h>
#define taskname "2078B"
using namespace std;
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
        if(k & 1){
            for(int i = 1; i + 1 < n; i++){
                cout << n << " ";
            }
        }
        else{
            for(int i = 1; i + 1 < n; i++){
                cout << n - 1 << " ";
            }
        }
        cout << n << " " << n - 1 << "\n";
    }
}