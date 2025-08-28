#include<bits/stdc++.h>
#define taskname "2047E"
using namespace std;
struct FenwickTree{
	vector<int>bit;
	int n;
	FenwickTree(){}
	FenwickTree(int n){
		bit.assign((this->n = n) + 1, 0);
	}
	void update(int p, int x){
		for(; p <= n; p += p & -p){
			bit[p] += x;
		}
	}
	int get(int p){
		int ans = 0;
		for(; p > 0; p -= p & -p){
			ans += bit[p];
		}
		return ans;
	}
};
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, ans = 0, x_ans = 0, y_ans = 0;
		cin >> n;
		vector<int>x(n), y(n);
		for(int i = 0; i < n; i++){
			cin >> x[i] >> y[i];
		}
		vector<int>_x = x, _y = y;
		sort(_x.begin(), _x.end());
		sort(_y.begin(), _y.end());
		vector<vector<int>>event(n + 1);
		for(int i = 0; i < n; i++){
			event[lower_bound(_x.begin(), _x.end(), x[i]) - _x.begin() + 1].emplace_back(lower_bound(_y.begin(), _y.end(), y[i]) - _y.begin() + 1);
		}
		int low = 1, high = n >> 1;
		while(low <= high){
			int mid = (low + high) >> 1;
			bool can = false;
			vector<int>cut_point(n + 1);
			priority_queue<int>pq;
			FenwickTree up(n), down(n);
			for(int i = n; i > 0; i--){
				for(int& j : event[i]){
					pq.push(j);
					up.update(j, 1);
				}
				while(pq.size() > mid){
					pq.pop();
				}
				cut_point[i] = (pq.size() < mid ? n + 2 : pq.top());
			}
			while(!pq.empty()){
				pq.pop();
			}
			for(int i = 2, pre = 1, cnt_up = n, cnt_down = 0; i <= n; i++){
				if(_x[i - 1] == _x[pre - 1]){
					continue;
				}
				for(int& j : event[pre]){
					pq.push(j);
					up.update(j, -1);
					down.update(j, 1);
					cnt_up--;
					cnt_down++;
				}
				pre = i;
				while(pq.size() > mid){
					pq.pop();
				}
				if(pq.size() == mid && cut_point[i] != n + 2){
					int p = max(cut_point[i], pq.top()), left_up = up.get(p), left_down = down.get(p);
					if(min({left_up, cnt_up - left_up, left_down, cnt_down - left_down}) >= mid){
						can = true;
						x_ans = _x[i - 1];
						y_ans = _y[p - 1] + 1;
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
		cout << ans << "\n" << x_ans << " " << y_ans << "\n";
	}
}