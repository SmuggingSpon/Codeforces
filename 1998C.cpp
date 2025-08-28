#include<bits/stdc++.h>
#define taskname "1998C"
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
		for(int i = 0; i < n; i++){
			cin >> a[a[i].second = i].first;
		}
		vector<bool>b(n);
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			b[i] = (x == 1);
		}
		sort(a.begin(), a.end());
		ll ans = a[n - 1].first + a[(n >> 1) - 1].first;
		for(int i = n - 1; i > -1; i--){
			if(b[a[i].second]){
				if(a[i].first + k >= a[n - 1].first){
					vector<pair<int, int>>temp = a;
					temp.erase(temp.begin() + i);
					maximize(ans, ll(a[i].first + k) + temp[(n >> 1) - 1].first);
				}
				break;
			}
		}
		int low = 1, high = 2e9, p;
		while(low <= high){
			int mid = low + ((high - low) >> 1), temp = k, cnt = 0;
			for(int i = n - 1; i > -1; i--){
				if(a[i].first >= mid){
					cnt++;
				}
				else if(b[a[i].second] && temp >= mid - a[i].first){
					temp -= mid - a[i].first;
					cnt++;
				}
			}
			if(cnt >= ((n + 3) >> 1)){
				low = (p = mid) + 1;
			}
			else{
				high = mid - 1;
			}
		}
		cout << max(ans, ll(p) + a[n - 1].first) << "\n";
	}
}