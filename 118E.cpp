#include<bits/stdc++.h>
#define taskname "118E"
using namespace std;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
const int lim = 1e5 + 5;
const int LIM = 3e5 + 5;
int n, m, t_dfs = 0, low[lim], num[lim], u[LIM], v[LIM];
vector<int>g[lim];
void dfs(int s, int p = -1){
	low[s] = num[s] = ++t_dfs;
	for(int& i : g[s]){
		int d = u[i] ^ v[i] ^ s;
		if(d != p){
			if(num[d] == 0){
				dfs(d, s);
				minimize(low[s], low[d]);
				if(num[d] == low[d]){
					cout << 0;
					exit(0);
				}
				if(u[i] == d){
					swap(u[i], v[i]);
				}
			}
			else{
				minimize(low[s], num[d]);
				if((num[d] < num[s] && u[i] == d) || (num[d] > num[s] && u[i] == s)){
					swap(u[i], v[i]);
				} 
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> u[i] >> v[i];
		g[u[i]].emplace_back(i);
		g[v[i]].emplace_back(i);
	}
	memset(num, 0, sizeof(num));
	dfs(1);
	for(int i = 0; i < m; i++){
		cout << u[i] << " " << v[i] << "\n";
	}
}