#include<bits/stdc++.h>
#define taskname "2085C"
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    int _t;
    cin >> _t;
    for(int _ = 0; _ < _t; _++){
        ll x, y;
        cin >> x >> y;
        cout << (x == y ? -1 : INF - max(x, y)) << "\n";
    }
}