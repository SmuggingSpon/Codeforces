#include<bits/stdc++.h>
#define taskname "2070B"
using namespace std;
typedef long long ll;
void solve(){
    int n, x;
    ll k;
    string s;
    cin >> n >> x >> k >> s;
    for(char& c : s){
        if(x == 0){
            break;
        }
        if(k-- == 0){
            return void(cout << "0\n");
        } 
        if(c == 'L'){
            x--;
        }
        else{
            x++;
        }        
    }
    if(x != 0){
        return void(cout << "0\n");
    }
    int cycle = 0;
    for(char& c : s){
        if(c == 'L'){
            x--;
        }
        else{
            x++;
        }
        cycle++;
        if(x == 0){
            break;
        }
    }
    if(x != 0){
        return void(cout << "1\n");
    }
    cout << k / cycle + 1 << "\n";
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    int _t;
    cin >> _t;
    for(int _ = 0; _ < _t; _++){
        solve();
    }
}