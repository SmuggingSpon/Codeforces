#include<bits/stdc++.h>
#define taskname "1927C"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, m, k;
		cin >> n >> m >> k;
		vector<bool>a(k + 1, false), b(k + 1, false);
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			if(x <= k){
				a[x] = true; 
			}
		}
		for(int i = 0; i < m; i++){
			int x;
			cin >> x;
			if(x <= k){
				b[x] = true;
			}
		}
		int cnt_a = 0, cnt_b = 0;
		bool ans = true;
		for(int i = 1; i <= k; i++){
			if(!a[i] && !b[i]){
				ans = false;
				break;
			}
			else if(!a[i]){
				cnt_b++;
			}
			else if(!b[i]){
				cnt_a++;
			}
		}
		cout << (min(n, m) >= (k >> 1) && cnt_a <= (k >> 1) && cnt_b <= (k >> 1) && ans ? "YES\n" : "NO\n");
	}
}