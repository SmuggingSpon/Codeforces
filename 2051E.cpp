#include<bits/stdc++.h>
#define taskname "2051E"
using namespace std;
typedef long long ll;
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
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
		int n, k;
		cin >> n >> k;
		vector<pair<int, int>>a(n);
		vector<int>event_time(1, -1);
		for(int i = 0; i < n; i++){
			cin >> a[i].first;
			event_time.push_back(a[i].first);
		}
		for(int i = 0; i < n; i++){
			cin >> a[i].second;
			event_time.push_back(a[i].second);
		}
		sort(a.begin(), a.end());
		sort(event_time.begin(), event_time.end());
		priority_queue<int, vector<int>, greater<int>>pq;
		ll ans = 0;
		for(int i = 1, j = 0, customer = n; i < event_time.size(); i++){
			int t = event_time[i];
			if(t != event_time[i - 1]){
				while(j < n && a[j].first < t){
					pq.push(a[j++].second);
				}
				while(!pq.empty() && pq.top() < t){
					pq.pop();
					customer--;
				}
				if(pq.size() <= k){
					maximize(ans, 1LL * t * customer);
				}
			}
		}
		cout << ans << "\n";
	}
}
