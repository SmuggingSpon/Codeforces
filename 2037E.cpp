#include<bits/stdc++.h>
#define taskname "2037E"
using namespace std;
int f(int l, int r){
	cout << "? " << l << " " << r << endl;
	int x;
	cin >> x;
	return x;
}
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
		int cnt = f(1, n);
		if(cnt == 0){
			cout << "! IMPOSSIBLE" << endl;
			continue;
		}
		vector<int>ans(n + 1);
		for(int i = 1; i < n; i++){
			int x = f(i, i + 1);
			if(x == 1){
				ans[i] = 0;
				int cnt_1 = ans[i + 1] = 1;
				for(int j = i + 2; j <= n; j++){
					int y = f(i, j);
					if(x == y){
						ans[j] = 0;
					}
					else{
						ans[j] = 1;
						x = y;
						cnt_1++;
					}
				}
				cnt -= x;
				while(cnt > 0){
					cnt -= cnt_1;
					ans[--i] = 0;
				}
				while(i > 0){
					ans[--i] = 1;
				}
				break;
			}
		}
		cout << "! ";
		for(int i = 1; i <= n; i++){
			cout << ans[i];
		}
		cout << endl;
	}
}