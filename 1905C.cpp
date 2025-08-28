#include<bits/stdc++.h>
#define taskname "1905C"
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
		if(n == 1){
			cout << "0\n";
			continue;
		}
		vector<int>suf(n);
		suf[n - 1] = n - 1;
		for(int i = n - 2; i > -1; i--){
			suf[i] = (s[i] >= s[suf[i + 1]] ? i : suf[i + 1]);
		}
		vector<int>p;
		p.emplace_back(suf[0]);
		while(p.back() < n - 1){
			p.emplace_back(suf[p.back() + 1]);
		}
		string S = s;
		for(int i = p.size() - 1; i > -1; i--){
			s[p[i]] = S[p[p.size() - i - 1]];
		}
		bool can = true;
		for(int i = 1; i < n; i++){
			if(s[i] < s[i - 1]){
				can = false;
				break;
			}
		}
		if(!can){
			cout << "-1\n";
		}
		else{
			int ans = p.size() - 1;
			char init = S[p[0]];
			for(int i = 1; i < p.size(); i++){
				if(S[p[i]] != init || p[p.size() - i] - p[p.size() - i - 1] > 1){
					break;
				}
				ans--;
			}
			cout << ans << "\n";
		} 
	}
}