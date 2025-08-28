#include<bits/stdc++.h>
#define taskname "2029F"
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
		string s;
		cin >> n >> s;
		int l = 0, r = n - 1;
		vector<int>R, B;
		while(r > -1 && s[r] == s[l]){
			r--;
		}
		if(r == -1){
			cout << "YES\n";
			continue;
		}
		if(r < n - 1){
			while(s[l] == s[0]){
				l++;
			}
			if(s[0] == 'R'){
				R.emplace_back(n - 1 - r + l);
			}
			else{
				B.emplace_back(n - 1 - r + l);
			}
		}
		while(l <= r){
			int L = l++;
			while(l <= r && s[l] == s[L]){
				l++;
			}
			if(s[L] == 'R'){
				R.emplace_back(l - L);
			}
			else{
				B.emplace_back(l - L);
			}
		}
		sort(R.begin(), R.end());
		sort(B.begin(), B.end());
		if(R.back() > 1 && B.back() > 1){
			cout << "NO\n";
			continue;
		}
		if(R.back() == 1){
			swap(R, B);
		}
		int even = 0;
		for(int& x : R){
			even += ~x & 1;
		}
		cout << (even == 1 || R.size() == 1 ? "YES\n" : "NO\n");
	}
}