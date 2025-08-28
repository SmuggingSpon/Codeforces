#include<bits/stdc++.h>
#define taskname "1934D1"
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
		ll n, m;
		cin >> n >> m;
		if(__builtin_popcountll(n) == 1){
			cout << "-1\n";
			continue;
		}
		bool have_ans = true;
		for(int i = 60; i > -1; i--){
			if(1LL << i & n){
				for(int j = i - 1; (1LL << j & n) == 0; j--){
					if(1LL << j & m){
						have_ans = false;
						break;
					}
				}
				break;
			}
		}
		if(have_ans){
			stack<int>st;
			vector<ll>ans;
			for(int i = 0; i < 60; i++){
				bool N = (1LL << i & n) > 0, M = (1LL << i & m) > 0;
				if(N && !M){
					ll value = 1LL << i;
					while(!st.empty()){
						value |= 1LL << st.top();
						st.pop();
					}
					ans.emplace_back(value);
				}
				else if(!N && M){
					st.push(i);
				}
			}
			cout << ans.size() << "\n" << n << " ";
			for(ll& x : ans){
				cout << (n ^= x) << " ";
			}
			cout << "\n";
		}
		else{
			cout << "-1\n";
		}
	}
}