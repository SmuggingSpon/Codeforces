#include<bits/stdc++.h>
#define taskname "1987B"
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
		int n;
		cin >> n;
		vector<int>a(n);
		for(int& x : a){
			cin >> x;
		}
		vector<int>value(1, 0);
		for(int i = 1, index = 0; i < n; i++){
			if(a[i] >= a[index]){
				index = i;
			}
			else{
				value.emplace_back(a[index] - a[i]);
			}
		}
		sort(value.begin(), value.end());
		ll ans = 0;
		for(int i = 1; i < value.size(); i++){
			ans += 1LL * (int(value.size()) - i + 1) * (value[i] - value[i - 1]);
		}
		cout << ans << "\n";
	}
}