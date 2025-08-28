#include<bits/stdc++.h>
#define taskname "2029B"
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
		string a, b;
		cin >> n >> a >> b;
		vector<int>cnt = {count(a.begin(), a.end(), '0')};
		cnt.emplace_back(n - cnt[0]);
		for(int i = 0; i + 1 < n; i++){
			bool parity = bool((b[i] - 48) ^ 1);
			if(cnt[parity] == 0 || (cnt[parity] > 1 && cnt[!parity] == 0)){
				cnt[0] = -1;
				break;
			}
			cnt[parity]--;
		}
		cout << (cnt[0] == -1 ? "NO\n" : "YES\n");
	}
}