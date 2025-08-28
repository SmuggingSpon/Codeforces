#include<bits/stdc++.h>
#define taskname "1977D"
using namespace std;
typedef long long ll;
template<class T>bool maximize(T& a, T b){
	if(a < b){
		a = b;
		return true;
	}
	return false;
}
const int mod[2] = {2000000269, 2000002507};
const int base = 439;
const int lim = 3e5 + 5;
void add_0(int& a, int b){
	a = (ll(a) + b) % mod[0];
}
void add_1(int& a, int b){
	a = (ll(a) + b) % mod[1];
}
void sub_0(int& a, int b){
	a = (ll(a) - b + mod[0]) % mod[0];
}
void sub_1(int& a, int b){
	a = (ll(a) - b + mod[1]) % mod[1];
}
int pw[lim][2];
int get_flip(const int id, const int& index, int hash_value, char ch){
	if(ch == '0'){
		if(id == 0){
			add_0(hash_value, pw[index][0]);
		}
		else{
			add_1(hash_value, pw[index][1]);
		}
	}
	else{
		if(id == 0){
			sub_0(hash_value, pw[index][0]);
		}
		else{
			sub_1(hash_value, pw[index][1]);
		}
	}
	return hash_value;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	for(int i = pw[0][0] = pw[0][1] = 1; i < lim; i++){
		pw[i][0] = 1LL * pw[i - 1][0] * base % mod[0];
		pw[i][1] = 1LL * pw[i - 1][1] * base % mod[1];
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>s(n + 1, vector<char>(m + 1));
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> s[i][j];
			}
		}
		map<pair<int, int>, int>cnt;
		for(int j = 1; j <= m; j++){
			int value_0 = 0, value_1 = 0;
			for(int i = 1; i <= n; i++){
				if(s[i][j] == '0'){
					add_0(value_0, pw[i][0]);
					add_1(value_1, pw[i][1]);
				}
				else{
					add_0(value_0, (ll(pw[i][0]) << 1LL) % mod[0]);
					add_1(value_1, (ll(pw[i][1]) << 1LL) % mod[1]);
				}
			}
			for(int i = 1; i <= n; i++){
				cnt[make_pair(get_flip(0, i, value_0, s[i][j]), get_flip(1, i, value_1, s[i][j]))]++;
			}
		}
		int ans = 0;
		pair<int, int>value;
		for(auto& it : cnt){
			if(maximize(ans, it.second)){
				value = it.first;
			}
		}
		cout << ans << "\n";
		for(int j = 1; j <= m; j++){
			int value_0 = 0, value_1 = 0;
			for(int i = 1; i <= n; i++){
				if(s[i][j] == '0'){
					add_0(value_0, pw[i][0]);
					add_1(value_1, pw[i][1]);
				}
				else{
					add_0(value_0, (ll(pw[i][0]) << 1LL) % mod[0]);
					add_1(value_1, (ll(pw[i][1]) << 1LL) % mod[1]);
				}
			}
			pair<int, int>current;
			for(int i = 1; i <= n; i++){
				current = make_pair(get_flip(0, i, value_0, s[i][j]), get_flip(1, i, value_1, s[i][j]));
				if(current == value){
					s[i][j] = (s[i][j] == '0' ? '1' : '0');
					for(int k = 1; k <= n; k++){
						cout << s[k][j];
					}
					cout << "\n";
					j = m;
					break;
				}
			}
		}
	}
}
