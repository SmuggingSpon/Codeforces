#include<bits/stdc++.h>
#define taskname "1935C"
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
		ll L;
		cin >> n >> L;
		vector<pair<int, int>>a(n);
		for(auto& [x, y] : a){
			cin >> x >> y;
		}
		sort(a.begin(), a.end(), [&] (auto i, auto j) -> bool{
			return i.second < j.second;
		});
		int low = 1, high = n, ans = 0;
		while(low <= high){
			int mid = (low + high) >> 1;
			bool can = false;
			for(int l = 0; l < n - mid + 1; l++){
				priority_queue<int>pq;
				ll sum = 0;
				for(int r = l; r < n; r++){
					if(pq.size() == mid){
						if(pq.top() > a[r].first){
							sum -= pq.top() - a[r].first;
							pq.pop();
							pq.push(a[r].first);
						}
					}
					else{
						sum += a[r].first;
						pq.push(a[r].first);
					}
					if(r - l + 1 >= mid && sum + a[r].second - a[l].second <= L){
						can = true;
						l = n;
						break;
					}
				}
			}
			if(can){
				low = (ans = mid) + 1;
			}
			else{
				high = mid - 1;
			}
		}
		cout << ans << "\n";
	}
}