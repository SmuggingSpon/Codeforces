#include<bits/stdc++.h>
#define taskname "1932C"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, m;
		cin >> n >> m;
		deque<int>d;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			d.emplace_back(x);
		}
		vector<int>value;
		string s;
		cin >> s;
		for(char& c : s){
			if(c == 'L'){
				value.emplace_back(d.front());
				d.pop_front();
			}
			else{
				value.emplace_back(d.back());
				d.pop_back();
			}
		}
		vector<int>ans(n + 2);
		ans[n] = 1;
		for(int i = n - 1; i > -1; i--){
			ans[i] = 1LL * ans[i + 1] * value[i] % m;
		}
		for(int i = 0; i < n; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
}