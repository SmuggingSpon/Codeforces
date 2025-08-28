#include<bits/stdc++.h>
#define taskname "1984D"
using namespace std;
typedef long long ll;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
const int INF = 1e9;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		string s, pat = "";
		cin >> s;
		vector<int>index(1, 0);
		for(int i = 0; i < s.size(); i++){
			if(s[i] != 'a'){
				pat += s[i];
				index.emplace_back(i + 1);
			}
		}
		if(pat.empty()){
			cout << int(s.size()) - 1 << "\n";
			continue;
		}
		index.emplace_back(int(s.size()) + 1);
		int n = pat.size();
		pat = '$' + pat;
		ll ans = 0;
		auto check = [&] (int L){
			for(int i = L + 1; i <= n; i += L){
				for(int j = 0; j < L; j++){
					if(pat[i + j] != pat[1 + j] || (j > 0 && index[i + j] - index[i + j - 1] != index[1 + j] - index[j])){
						return;
					}
				}
			}
			int sum = INF, left = index[1] - 1, right = int(s.size()) - index[n];
			for(int i = L; i < n; i += L){
				minimize(sum, index[i + 1] - index[i] - 1);
			}
			for(int i = 0; i <= min(left, sum); i++){
				ans += min(right, sum - i) + 1;
			}
		};
		for(int i = 1; i * i <= n; i++){
			if(n % i == 0){
				check(i);
				if(i * i != n){
					check(n / i);
				}
			}
		}
		cout << ans << "\n";
	}
}