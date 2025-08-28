#include<bits/stdc++.h>
#define taskname "2031E"
using namespace std;
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
const int lim = 1e6 + 5;
int n, h[lim];
vector<int>g[lim];
void dfs(int s){
	if(g[s].empty()){
		h[s] = 0;
		return;
	}
	vector<int>H;
	for(int& d : g[s]){
		dfs(d);
		H.emplace_back(h[d]);
	}
	sort(H.begin(), H.end(), greater<int>());
	int low = H.back() + 1, high = n;
	while(low <= high){
		int mid = (low + high) >> 1, cur = 1, pre = 0;
		for(int& x : H){
			if(cur == 0){
				cur = -1;
				break;
			}
			int T = mid - x;
			for(int i = pre; i < T; i++){
				if((cur <<= 1) > H.size()){
					break;
				}
			}
			if(cur > H.size()){
				break;
			}
			cur--;
			pre = T;
		}
		if(cur > -1){
			high = (h[s] = mid) - 1;
		}
		else{
			low = mid + 1;
		}
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
			g[i].clear();
		}	
		for(int i = 2; i <= n; i++){
			int p;
			cin >> p;
			g[p].emplace_back(i);
		}
		dfs(1);
		cout << h[1] << "\n";
	}
}