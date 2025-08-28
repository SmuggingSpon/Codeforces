#include<bits/stdc++.h>
#define taskname "2031C"
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
		if((n & 1) && n < 27){
			cout << "-1\n";
		}
		else if(n == 27){
			vector<int>ans(n + 1);
			ans[1] = ans[10] = ans[26] = 1;
			for(int i = 2; i < 10; i += 2){
				ans[i] = ans[i + 1] = i;
			}
			for(int i = 11; i < 23; i += 2){
				ans[i] = ans[i + 1] = i;
			}
			ans[24] = ans[25] = 1000000;
			ans[23] = ans[27] = 99999;
			for(int i = 1; i <= n; i++){
				cout << ans[i] << " ";
			}
			cout << "\n";
		}
		else if(n & 1){
			vector<int>ans(n + 1);
			ans[1] = ans[10] = ans[26] = 1;
			for(int i = 2; i < 10; i += 2){
				ans[i] = ans[i + 1] = i;
			}
			for(int i = 11; i < 25; i += 2){
				ans[i] = ans[i + 1] = i; 
			}
			int cnt = 1e6;
			ans[25] = ans[29] = cnt;
			ans[27] = ans[28] = --cnt;
			for(int i = 30; i < n; i += 2){
				ans[i] = ans[i + 1] = --cnt;
			}
			for(int i = 1; i <= n; i++){
				cout << ans[i] << " ";
			}
			cout << "\n";
		}
		else{
			for(int i = 1; i < n; i += 2){
				cout << i << " " << i << " ";
			}
			cout << "\n";
		}
	}
}