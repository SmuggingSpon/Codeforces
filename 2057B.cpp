#include<bits/stdc++.h>
#define taskname "2057B"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, k;
		cin >> n >> k;
		map<int, int>cnt;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			cnt[x]++;
		}
		priority_queue<int, vector<int>, greater<int>>pq;
		for(auto& [u, v] : cnt){
			pq.push(v);
		}
		while(pq.size() > 1){
			if(pq.top() > k){
				break;
			}
			k -= pq.top();
			pq.pop();
		}
		cout << pq.size() << "\n";
	}
}