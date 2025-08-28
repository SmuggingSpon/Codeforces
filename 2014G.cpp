#include<bits/stdc++.h>
#define taskname "2014G"
using namespace std;
const int INF = 1e9;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t; 
	for(int _ = 0; _ < _t; _++){
		int n, m, k, ans = 0;
		cin >> n >> m >> k;
		vector<pair<int, int>>milk(n), current;
		for(auto& [d, a] : milk){
			cin >> d >> a;
		}
		milk.emplace_back(INF, -1);
		for(int i = 0; i < n; i++){
			current.emplace_back(milk[i]);
			int p = milk[i].first;
			while(!current.empty() && p < milk[i + 1].first){
				auto [d, a] = current.back();
				current.pop_back();
				if(a < m){
					if(current.empty()){
						break;
					}
					current.back().second += a;
					continue;
				}
				if(d + k <= p){
					current.clear();
					break;
				}
				int cnt = min(milk[i + 1].first, d + k) - p;
				if(1LL * cnt * m >= a){
					ans += a / m;
					p += a / m;
					if((a %= m) != 0){
						if(current.empty()){
							if(p == milk[i + 1].first){
								current.emplace_back(d, a);
							}
							break;
						}
						current.back().second += a;
						continue;
					}
				}
				else{
					ans += cnt;
					current.emplace_back(d, a - m * cnt);
					break;
				}
			}
		}
		cout << ans << "\n";
	}
}