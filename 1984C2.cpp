#include<bits/stdc++.h>
#define taskname "1984C2"
using namespace std;
typedef long long ll;
const int mod = 998244353;
void add(int& a, int b){
	if((a += b) >= mod){
		a -= mod;
	}
}
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
		ll current_max = 0, current_min = 0;
		int cnt_max = 1, cnt_min = 1;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			int temp_cnt_max = cnt_max, temp_cnt_min = cnt_min;
			vector<ll>value_max = {current_max + x, abs(current_max + x)}, value_min = {current_min + x, abs(current_min + x)};
			ll next_max = max({value_max[0], value_max[1], value_min[0], value_min[1]}), next_min = min({value_max[0], value_max[1], value_min[0], value_min[1]});
			cnt_max = cnt_min = 0;
			for(int j = 0; j < 2; j++){
				if(next_max == value_max[j]){
					add(cnt_max, temp_cnt_max);
				}
				if(next_max == value_min[j] && current_max != current_min){
					add(cnt_max, temp_cnt_min);
				}
				if(next_min == value_max[j] && current_max != current_min){
					add(cnt_min, temp_cnt_max);
				}
				if(next_min == value_min[j]){
					add(cnt_min, temp_cnt_min);
				}
			}
			current_max = next_max;
			current_min = next_min;
		}
		cout << cnt_max << "\n";
	}
}