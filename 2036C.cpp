#include<bits/stdc++.h>
#define taskname "2036C"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		string s;
		int q, cnt = 0;
		cin >> s >> q;
		for(int i = 3; i < s.size(); i++){
			if(s[i - 3] == '1' && s[i - 2] == '1' && s[i - 1] == '0' && s[i] == '0'){
				cnt++;
			}
		}
		auto work = [&] (int p, int x){
			for(int i = max(0, p - 3); i <= min(p, int(s.size()) - 4); i++){
				if(s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0'){
					cnt += x;
				}
			}
		};
		for(int _q = 0; _q < q; _q++){
			int i;
			char v;
			cin >> i >> v;
			work(--i, -1);
			s[i] = v;
			work(i, 1);
			cout << (cnt > 0 ? "YES\n" : "NO\n");
		}
	}
}