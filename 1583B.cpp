#include<bits/stdc++.h>
#define taskname "1583B"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _  = 0; _ < _t; _++){
		int n, m;
		cin >> n >> m;
		vector<bool>vis(n + 1, false);
		for(int i = 0; i < m; i++){
			int a, b, c;
			cin >> a >> b >> c;
			vis[b] = true;
		}
		for(int i = 1; i <= n; i++){
			if(!vis[i]){
				for(int j = 1; j <= n; j++){
					if(j != i){
						cout << i << " " << j << "\n";
					}
				}
				break;
			}
		}
	}
}