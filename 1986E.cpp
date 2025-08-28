#include<bits/stdc++.h>
#define taskname "1986E"
using namespace std;
typedef long long ll;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
const ll INF = 1e18;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, k, cnt = 0;
		cin >> n >> k;
		map<int, vector<int>>value;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			value[x % k].emplace_back(x);
		}
		ll ans = 0;
		for(auto& [mod, ve] : value){
			if(ve.size() & 1){
				if(++cnt != (n & 1)){
					ans = -k;
					break;
				}
				sort(ve.begin(), ve.end());
				vector<ll>left(2, 0), right(2, 0);
				for(int i = 0; i < ve.size(); i++){
					right[i & 1] += ve[i];
				}
				ll sum = INF;
				for(int i = 0; i < ve.size(); i++){
					right[i & 1] -= ve[i];
					minimize(sum, left[1] - left[0] + right[0] - right[1]);
					left[i & 1] += ve[i];
				}
				ans += sum;
				continue;
			}
			sort(ve.begin(), ve.end());
			for(int i = 1; i < ve.size(); i += 2){
				ans += ve[i] - ve[i - 1];
			}
		}
		cout << ans / k << "\n";
	}
}