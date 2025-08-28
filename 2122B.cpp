#include<bits/stdc++.h>
#define taskname "2122B"
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
		ll ans = 0;
		for(int i = 0; i < n; i++){
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			if(b > d){
				ans += b - d + a;
			}
			else if(a > c){
				ans += a - c;
			}
		}
		cout << ans << "\n";
	}
}