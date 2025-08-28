#include<bits/stdc++.h>
#define taskname "2042B"
using namespace std;
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
		vector<int>color(n + 1, 0);
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			color[x]++;
		}
		int cnt = 0, ans = 0;
		for(int i = 1; i <= n; i++){
			if(color[i] == 1){
				cnt++;
			}
			else if(color[i] > 1){
				ans++;
			}
		}
		cout << ans + (((cnt + 1) >> 1) << 1) << "\n";
	}
}