#include<bits/stdc++.h>
#define taskname "2042C"
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, k, ans = -1;
		string s;
		cin >> n >> k >> s;
		vector<int>cnt = {0};
		for(int i = n - 1; i > 0; i--){
			if(s[i] == '0'){
				cnt.emplace_back(cnt.back() - 1);
			}
			else{
				cnt.emplace_back(cnt.back() + 1);
			}
		}
		sort(cnt.begin(), cnt.end(), greater<int>());
		for(int i = 0; i < n; i++){
			if(cnt[i] < 0){
				break;
			}
			if((k -= cnt[i]) < 1){
				ans = i + 2;
				break;
			}
		}
		cout << ans << "\n";
	}
}