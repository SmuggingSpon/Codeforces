#include<bits/stdc++.h>
#define taskname "2064B"
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
		vector<int>a(n), cnt(n + 1, 0);
		for(int& x : a){
			cin >> x;
			cnt[x]++;
		}
		vector<bool>mark(n, false);
		for(int i = 0; i < n; i++){
			if(cnt[a[i]] == 1){
				mark[i] = true;
			}
		}
		int L = -1, R = -2;
		for(int i = 0; i < n; i++){
			if(mark[i]){
				int l = i, r = i;
				while(r < n && mark[r]){
					r++;
				}
				i = r--;
				if(r - l > R - L){
					L = l;
					R = r;
				}
			}
		}
		if(L == -1){
			cout << "0\n";
		}
		else{
			cout << L + 1 << " " << R + 1 << "\n";
		}
	}
}