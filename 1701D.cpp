#include<bits/stdc++.h>
#define taskname "1701D"
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
		vector<vector<pair<int, int>>>event(n + 1);
		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;
			if(x == 0){
				event[n].emplace_back(i + 1, i);
			}
			else{
				event[i / x].emplace_back(i / (x + 1) + 1, i);
			}
		}
		vector<int>ans(n + 1);
		priority_queue<pair<int, int>>pq;
		for(int i = n; i > 0; i--){
			for(pair<int, int>& it : event[i]){
				pq.push(it);
			}
			ans[pq.top().second] = i;
			pq.pop();
		}
		for(int i = 1; i <= n; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
}