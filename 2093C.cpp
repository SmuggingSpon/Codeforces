#include<bits/stdc++.h>
#define taskname "2093C"
using namespace std;
bool is_prime(int n){
    if(n == 2 || n == 3){
        return true;
    }
    if(n == 1 || (~n & 1) || n % 3 == 0){
        return false;
    }
    for(int i = 5; i * i <= n; i += 6){
        if(n % i == 0 || n % (i + 2) == 0){
            return false;
        }
    }
    return true;
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
        cin >> n >> k;
        if(k > 1){
            if(n > 1){
                cout << "NO\n";
            }
            else{
                for(int i = 1; i < k; i++){
                    n = (n << 3) + (n << 1) + 1;
                }
                cout << (is_prime(n) ? "YES\n" : "NO\n");
            }
            continue;
        }
        cout << (is_prime(n) ? "YES\n" : "NO\n");
    }
}