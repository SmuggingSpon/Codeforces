#include<bits/stdc++.h>
#define taskname "1943A"
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
		vector<int>cnt(n + 1, 0);
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			cnt[x]++;
		}
		int cnt_1 = 2;
		for(int i = 0; i <= n; i++){
			if(cnt[i] == 0 || (cnt[i] == 1 && --cnt_1 == 0)){
				cout << i << "\n";
				break;
			}
		}	
	}
}