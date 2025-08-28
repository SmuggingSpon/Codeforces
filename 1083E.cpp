#include<bits/stdc++.h>
#define taskname "1083E"
using namespace std;
typedef long long ll;
const int lim = 1e6 + 5;
struct Data{
	int x, y;
	ll value;
	bool operator <(Data& other){
		return this->x < other.x;
	}
};
Data a[lim];
ll dp[lim];
double slope(int i, int j){
	return double(dp[i] - dp[j]) / double(a[i].x - a[j].x);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].x >> a[i].y >> a[i].value;
	}
	sort(a + 1, a + n + 1);
	deque<int>d;
	d.push_back(a[0].x = a[0].y = a[0].value = dp[0] = 0);
	for(int i = 1; i <= n; i++){
		while(d.size() > 1 && slope(d[0], d[1]) >= double(a[i].y)){
			d.pop_front();
		}
		int j = d.front();
		dp[i] = 1LL * a[i].x * a[i].y - a[i].value - 1LL * a[j].x * a[i].y + dp[j];
		while(d.size() > 1 && slope(d[d.size() - 2], d.back()) <= slope(d.back(), i)){
			d.pop_back();
		}  
		d.push_back(i);
	}
	cout << *max_element(dp + 1, dp + n + 1);
}