#include<bits/stdc++.h>
#define taskname "1913C"
using namespace std;
int cnt[30];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	memset(cnt, 0, sizeof(cnt));
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		char type;
		cin >> type;
		if(type == '1'){
			int x;
			cin >> x;
			cnt[x]++;
		}
		else{
			int x;
			cin >> x;
			for(int i = 29; i > -1; i--){
				int need = x / (1 << i);
				x -= min(cnt[i], need) * (1 << i); 				
			}
			cout << (x == 0 ? "YES\n" : "NO\n");
		}
	}
}