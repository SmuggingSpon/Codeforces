#include<bits/stdc++.h>
#define taskname "1980C"
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
		vector<int>a(n), b(n);
		for(int& x : a){
			cin >> x;
		}
		for(int& x : b){
			cin >> x;
		}
		map<int, int>cnt;
		for(int i = 0; i < n; i++){
			if(a[i] != b[i]){
				cnt[b[i]]++;
			}
		}
		int m;
		cin >> m;
		vector<int>d(m);
		for(int& x : d){
			cin >> x;
		}
		if(cnt.find(d[m - 1]) == cnt.end() && find(b.begin(), b.end(), d[m - 1]) == b.end()){
			cout << "NO\n";
			continue;
		}
		for(int i = m - 1; i > -1; i--){
			auto it = cnt.find(d[i]);
			if(it != cnt.end() && --cnt[d[i]] == 0){
				cnt.erase(d[i]);
			}
		}
		cout << (cnt.empty() ? "YES\n" : "NO\n");
	}
}