#include<bits/stdc++.h>
#define taskname "319C"
using namespace std;
typedef long long ll;
const int lim = 1e5 + 5;
int a[lim], b[lim];
ll dp[lim];
double slope(int i, int j){
	return double(dp[i] - dp[j]) / (b[j] - b[i]);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}
	deque<int>d;
	d.push_back(1);
	dp[1] = 0;
	for(int i = 2; i <= n; i++){
		while(d.size() > 1 && slope(d.front(), d[1]) <= double(a[i])){
			d.pop_front();
		}
		int j = d.front();
		dp[i] = dp[j] + 1LL * b[j] * a[i];
		while(d.size() > 1 && slope(d.back(), d[d.size() - 2]) >= slope(d.back(), i)){
			d.pop_back();
		}
		d.push_back(i);
	}
	cout << dp[n];
}