#include<bits/stdc++.h>
#define taskname "1977C"
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
		int n;
		cin >> n;
		map<int, bool>present;
		vector<int>a(n);
		for(int& x : a){
			cin >> x;
			present[x] = true;
		}
		ll L = 1;
		bool ans_is_n = false;
		for(int& x : a){
			L = 1LL * x / __gcd(L, ll(x)) * L;
			if(L > 1000000000){
				ans_is_n = true;
				break;
			}
		}
		if(ans_is_n || present.find(L) == present.end()){
			cout << n << "\n";
			continue;
		}
		int E = *max_element(a.begin(), a.end()), ans = 0;
		auto check_var = [&] (int d){
			if(present.find(d) == present.end()){
				int current = 1, sum_ans = 0;
				for(int& x : a){
					if(d % x == 0){
						current = current / __gcd(current, x) * x;
						sum_ans++;
					}
				}
				if(current == d){
					maximize(ans, sum_ans);
				}
			}
		};
		for(int i = 1; i * i <= E; i++){
			if(E % i == 0){
				check_var(i);
				if(i * i != E){
					check_var(E / i);
				}
			}
		}
		cout << ans << "\n";
	}
}