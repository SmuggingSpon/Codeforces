#include<bits/stdc++.h>
#define taskname "2037D"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, m, L;
		cin >> n >> m >> L;
		vector<pair<int, int>>trap(n);
		for(auto& [l, r] : trap){
			cin >> l >> r;
		}
		vector<pair<int, int>>item(m);
		for(auto& [x, v] : item){
			cin >> x >> v;
		}
		int ans = 0, power = 1, id = 0;
		priority_queue<int>pq;
		for(auto& [l, r] : trap){
			while(id < m && item[id].first < l){
				pq.push(item[id++].second);
			}
			while(!pq.empty() && l - 1 + power <= r){
				power += pq.top();
				pq.pop();
				ans++;
			}
			if(l - 1 + power <= r){
				ans = -1;
				break;
			}
		}
		cout << ans << "\n";
	}
}