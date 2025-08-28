#include<bits/stdc++.h>
#define taskname "2034E"
using namespace std;
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
		if(n == 1){
			cout << (k == 1 ? "YES\n1\n" : "NO\n");
			continue;
		}
		if((~n & 1) && (k & 1) || k == 1){
			cout << "NO\n";
			continue;
		}
		if(n < 10){
			int gt = 1;
			for(int i = 2; i <= n; i++){
				gt *= i;
			}
			if(gt < k || k == gt - 1){
				cout << "NO\n";
				continue;
			}
		}
		cout << "YES\n";
		vector<vector<int>>perm;
		if(k & 1){
			k -= 3;
			vector<int>temp(n);
			iota(temp.begin(), temp.end(), 1);
			perm.emplace_back(temp);
			for(int i = 1; i <= n; i++){
				cout << i << " ";
			}
			temp.clear();
			cout << "\n";
			for(int i = (n >> 1) + 1; i <= n; i++){
				cout << i << " ";
				temp.emplace_back(i);
			}
			for(int i = 1; i <= (n >> 1); i++){
				cout << i << " ";
				temp.emplace_back(i);
			}
			perm.emplace_back(temp);
			temp.clear();
			cout << "\n";
			int S = (3 * (n + 1)) >> 1, cnt = 1;
			for(int i = (n >> 1) + 1; i <= n; i++){
				temp.emplace_back(S - i - cnt);
				cout << S - i - cnt++ << " ";
			}
			for(int i = 1; i <= (n >> 1); i++){
				temp.emplace_back(S - i - cnt);
				cout << S - i - cnt++ << " ";
			}
			perm.emplace_back(temp);
			cout << "\n";
		}
		vector<int>p(n);
		iota(p.begin(), p.end(), 1);
		for(int _ = k >> 1; _ > 0; _--){
			vector<int>temp;
			for(int& x : p){
				temp.emplace_back(n - x + 1);
			}
			bool can = true;
			for(auto& x : perm){
				if(x == p || x == temp){
					can = false;
					break;
				}
			}
			if(can){
				for(int& x : p){
					cout << x << " ";
				}
				cout << "\n";
				for(int& x : temp){
					cout << x << " ";
				}
				cout << "\n";
			}
			else{
				_++;
			}
			next_permutation(p.begin(), p.end());
		}
	}
}