#include<bits/stdc++.h>
#define taskname "1997D"
using namespace std;
typedef long long ll;
const int lim = 2e5 + 5;
const int INF = 1e9;
int n, a[lim];
vector<int>e[lim];
bool can;
void dfs(int s, int carry){
	if(carry > INF || (e[s].empty() && a[s] < carry)){
		can = false;
		return;
	}
	if(a[s] < carry){
		carry += carry - a[s];
	}
	for(int& d : e[s]){
		dfs(d, carry);
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
		cin >> n;
		for(int i = 1; i <= n; i++){
			e[i].clear();
		}
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 2; i <= n; i++){
			int x;
			cin >> x;
			e[x].emplace_back(i);
		}
		int low = 1, high = 1e9, ans = 0;
		while(low <= high){
			int mid = (low + high) >> 1;
			can = true;
			for(int& i : e[1]){
				dfs(i, mid);
			}
			if(can){
				low = (ans = mid) + 1;
			}	
			else{
				high = mid - 1;
			}
		}
		cout << a[1] + ans << "\n";
	}
}