#include<bits/stdc++.h>
#define taskname "1935B"
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
		vector<int>l(n), a(n);
		vector<bool>cnt(n + 1, false);
		for(int i = 0, mex = 0; i < n; i++){
			cin >> a[i];
			cnt[a[i]] = true;
			while(cnt[mex]){
				mex++;
			}
			l[i] = mex;
		}
		fill(cnt.begin(), cnt.end(), false);
		bool need = true;
		for(int i = n - 1, mex = 0; i > 0; i--){
			cnt[a[i]] = true;
			while(cnt[mex]){
				mex++;
			}
			if(mex == l[i - 1]){
				cout << "2\n1 " << i << "\n" << i + 1 << " " << n << "\n";
				need = false;
				break;
			}
		}
		if(need){
			cout << "-1\n";
		}
	}
}