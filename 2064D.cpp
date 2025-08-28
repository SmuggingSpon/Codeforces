#include<bits/stdc++.h>
#define taskname "2064D"
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
		int n, q;
		cin >> n >> q;
		vector<int>w(n + 1);
		vector<vector<int>>near(n + 1, vector<int>(30, -1));
		w[0] = 0;
		for(int i = 1; i <= n; i++){
			cin >> w[i];
			near[i] = near[i - 1];
			for(int j = 29; j > -1; j--){
				if(1 << j & w[i]){
					near[i][j] = i;
					break;
				}
			}
			w[i] ^= w[i - 1];
		}
		for(int __ = 0; __ < q; __++){
			int x, p = n;
			cin >> x;
			while(x > 0 && p > 0){
				for(int i = 29, up = 0; i > -1; i--){
					if(1 << i & x){
						int t = near[p][i];
						if(t < up){
							p = up;
							x = 0;
							break;
						}
						if(t == -1){
							p = 0;							
							break;
						}
						if((x ^= w[p] ^ w[t]) < (w[t] ^ w[t - 1])){
							p = t;
							x = 0;
							break;
						}
						x ^= w[t] ^ w[p = t - 1];
						break;
					}
					else{
						maximize(up, near[p][i]);
					}
				}
			}
			cout << n - p << " ";
		}
		cout << "\n";
	}	
}
