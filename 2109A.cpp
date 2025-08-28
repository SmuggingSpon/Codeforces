#include<bits/stdc++.h>
#define taskname "2109A"
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int>a(n + 1), cnt(n + 1, 0);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i < n; i++){
		if(a[i] == 1){
			if(cnt[i] == 0 || a[i + 1] == 0){
				cnt[i]++;
			}
			else{
				cnt[i + 1]++;
			}
		}
		else{
			cnt[i + 1]++;
		}
	}
	for(int i = 1; i <= n; i++){
		if((a[i] == 0 && cnt[i] > 0) || (a[i] == 1 && cnt[i] == 0)){
			return void(cout << "YES\n");
		}
	}
	cout << "NO\n";
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		solve();
	}
}