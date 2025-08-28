#include<bits/stdc++.h>
#define taskname "1920D"
using namespace std;
typedef long long ll;
const ll INF = 1e18;
template<class T1, class T2>void minimize(T1& a, T2 b){
	if(T2(a) > b){
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
		int n, q;
		cin >> n >> q;
		vector<pair<int, int>>query;
		ll cnt = 0;
		for(int i = 0; i < n; i++){
			int a, x;
			cin >> a >> x;
			if(cnt < INF){
				if(a == 1){
					cnt++;
					query.emplace_back(a, x);
				}
				else{
					x++;
					minimize(x, INF / cnt + (INF % cnt != 0));
					query.emplace_back(a, x);
					cnt *= x;
				}
			}
		}
		reverse(query.begin(), query.end());
		set<pair<ll, int>>ask;
		for(int i = 0; i < q; i++){
			ll x;
			cin >> x;
			ask.emplace(x, i);
		}
		vector<int>ans(q);
		for(auto& [type, x] : query){
			if(ask.empty()){
				break;
			}
			if(type == 1){
				while(!ask.empty() && ask.rbegin()->first == cnt){
					auto it = ask.rbegin();
					ans[it->second] = x;
					ask.erase(*it);
				}
				cnt--;
			}
			else{
				stack<pair<ll, int>>st;
				for(auto it = ask.upper_bound(make_pair(cnt /= ll(x), -1)); it != ask.end(); it = next(it)){
					st.emplace(*it);
				}
				while(!st.empty()){
					auto [x, y] = st.top();
					st.pop();
					ask.erase(make_pair(x, y));
					ask.emplace(x % cnt == 0 ? cnt : x % cnt, y);
				}
			}
		}
		for(int& x : ans){
			cout << x << " ";
		}
		cout << "\n";
	}
}