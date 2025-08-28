#include<bits/stdc++.h>
#define taskname "2093D"
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
        int n, q;
        cin >> n >> q;
        for(int _q = 0; _q < q; _q++){
            string type;
            cin >> type;
            if(type == "->"){
                int x, y;
                cin >> x >> y;
                ll ans = 1;
                for(int i = n - 1; i > -1; i--){
                    int d = 1 << i;
                    ll square_d = 1LL * d * d;
                    if(x > d && y > d){
                        ans += square_d;
                        x -= d;
                        y -= d;
                    }
                    else if(x > d){
                        ans += square_d << 1LL;
                        x -= d;
                    }
                    else if(y > d){
                        ans += square_d * 3LL;
                        y -= d;
                    }
                }
                cout << ans << "\n";
            }
            else{
                ll val;
                cin >> val;
                int x = 1, y = 1;
                for(int i = n - 1; i > -1; i--){
                    int d = 1 << i;
                    ll square_d = 1LL * d * d;
                    int div = (val - 1) / square_d;
                    if(div == 1){
                        x += d;
                        y += d;
                    }
                    else if(div == 2){
                        x += d;
                    }
                    else if(div == 3){
                        y += d;
                    }
                    val -= square_d * ll(div);
                }
                cout << x << " " << y << "\n";
            }
        }
    }
}