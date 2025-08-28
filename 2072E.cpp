#include<bits/stdc++.h>
#define taskname "2072E"
using namespace std;
const int LIM = 15e4;
int a[LIM];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	for(int i = 1; i < 501; i++){
		for(int j = (i * (i - 1)) >> 1, r = (i * (i + 1)) >> 1; j < r; j++){
			a[j] = i;
		}
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int k, X = 0, Y = 0;
		cin >> k;
		vector<pair<int, int>>ans;
		while(k > 0){
			int N = a[k];
			k -= (N * (N - 1)) >> 1;
			for(int _ = 0; _ < N; _++){
				ans.emplace_back(X, ++Y);
			}
			X++;
		}
		cout << ans.size() << "\n";
		for(auto& [x, y] : ans){
			cout << x << " " << y << "\n";
		}
	}
}