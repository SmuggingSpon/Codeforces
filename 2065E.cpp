#include<bits/stdc++.h>
#define taskname "2065E"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		vector<char>pat = {'0', '1'};
		vector<int>cnt(2);
		int k;
		cin >> cnt[0] >> cnt[1] >> k;
		if(cnt[0] < cnt[1]){
			swap(cnt[0], cnt[1]);
			swap(pat[0], pat[1]);
		}
		if(k < cnt[0] - cnt[1] || k > cnt[0]){
			cout << "-1\n";
			continue;
		}
		cout << string(k, pat[0]);
		cnt[0] -= k;
		bool current = true;
		while(cnt[current] > 0){
			cout << pat[current];
			cnt[current]--;
			current = !current;
		}
		cout << string(cnt[0], pat[0]) << string(cnt[1], pat[1]) << "\n";
	}
}