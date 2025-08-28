#include<bits/stdc++.h>
#define taskname "2063D"
using namespace std;
typedef long long ll;
template<class T>bool maximize(T& a, T b){
	if(a < b){
		a = b;
		return true;
	}
	return false;
}
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
		vector<int>a(n), b(m);
		for(int& x : a){
			cin >> x;
		}
		for(int& x : b){
			cin >> x;
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int k = 0;
		for(int ca = 0; (ca << 1) <= n && ca <= m; ca++){
			maximize(k, ca + min(n - (ca << 1), (m - ca) >> 1));
		}
		cout << k << "\n";
		priority_queue<pair<ll, int>>pq;
		for(int i = 0; n - i - 1 > i; i++){
			pq.emplace(ll(a[n - i - 1] - a[i]), 0);
		}
		for(int i = 0; m - i - 1 > i; i++){
			pq.emplace(ll(b[m - i - 1] - b[i]), 1);
		}
		priority_queue<int, vector<int>, greater<int>>A, B;
		ll ans = 0;
		int ca = 0, cb = 0;
		for(int __ = 0; __ < k; __++){
			auto [x, id] = pq.top();
			pq.pop();
			if(id == 0){
				ca++;
				A.push(x);
			}
			else{
				cb++;
				B.push(x);
			}
			ans += x;
			if((ca << 1) + cb <= n && (cb << 1) + ca <= m){
				cout << ans << " ";
			}
			else{
				__--;
				if((ca << 1) + cb > n && (cb << 1) + ca > m){
					if(id == 0){
						ca--;
						ans -= A.top();
						A.pop();
					}
					else{
						cb--;
						ans -= B.top();
						B.pop();
					}
				}
				else if((ca << 1) + cb > n){
					ca--;
					ans -= A.top();
					A.pop();
				}
				else{
					cb--;
					ans -= B.top();
					B.pop();
				}
			}
		}
		cout << "\n";
	}
}