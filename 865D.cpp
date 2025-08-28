#include<bits/stdc++.h>
#define taskname "865D"
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>>pq;
	ll ans = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(!pq.empty() && pq.top() < x){
			ans += x - pq.top();
			pq.pop();
			pq.push(x);
		}
		pq.push(x);
	}
	cout << ans;
}