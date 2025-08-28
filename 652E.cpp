#include<bits/stdc++.h>
#define taskname "652E"
using namespace std;
const int lim = 3e5 + 5;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
int n, m, time_dfs = 0, u[lim], v[lim], z[lim], num[lim], low[lim], lab[lim], h[lim], up[lim][19];
vector<int>bridge, g[lim], tree[lim];
int find_set(int N){
	while(N != lab[N]){
		N = lab[N] = lab[lab[N]];
	}
	return N;
}
void merge(int a, int b){
	lab[find_set(a)] = find_set(b);
}
void dfs_1(int s, int p = -1){
	num[s] = low[s] = ++time_dfs;
	for(int& i : g[s]){
		int d = u[i] ^ v[i] ^ s;
		if(d != p){
			if(num[d] == 0){
				dfs_1(d, s);
				minimize(low[s], low[d]);
			}
			else{
				minimize(low[s], num[d]);
			}
			if(low[d] > num[s]){
				bridge.emplace_back(i);
			}
			else{
				merge(u[i], v[i]);
			}
		}
	}
}
void dfs_2(int s){
	for(int& d : tree[s]){
		if(d != up[s][0]){
			h[d] = h[up[d][0] = s] + 1;
			for(int i = 1; i < 19; i++){
				up[d][i] = up[up[d][i - 1]][i - 1];
			} 
			dfs_2(d);
		}
	}
}
int lca(int u, int v){
	if(h[u] < h[v]){
		swap(u, v);
	}
	for(int k = h[u] - h[v], i = 0; i < 19; i++){
		if(1 << i & k){
			u = up[u][i];
		}
	}
	if(u == v){
		return u;
	}
	for(int i = 18; i > -1; i--){
		if(up[u][i] != up[v][i]){
			u = up[u][i];
			v = up[v][i];
		}
	}
	return up[u][0];
}
int distance(int u, int v){
	return h[u] + h[v] - (h[lca(u, v)] << 1);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> u[i] >> v[i] >> z[i];
		g[u[i]].emplace_back(i);
		g[v[i]].emplace_back(i);
	}
	memset(num, 0, sizeof(num));
    iota(lab + 1, lab + n + 1, 1);
	dfs_1(1);
	for(int& i : bridge){
		int U = find_set(u[i]), V = find_set(v[i]);
		tree[U].emplace_back(V);
		tree[V].emplace_back(U);		
	}
	memset(up, h[find_set(1)] = 0, sizeof(up));
	dfs_2(find_set(1));
	int a, b;
	cin >> a >> b;
	for(int i = 0, d = distance(a = find_set(a), b = find_set(b)); i < m; i++){
        if(z[i] == 1){
            if((u[i] = find_set(u[i])) == (v[i] = find_set(v[i]))){
                if(distance(a, u[i]) + distance(u[i], b) == d){
                    return cout << "YES", 0;
                }
            }
            else if(distance(a, u[i]) + distance(b, v[i]) + 1 == d || distance(a, v[i]) + distance(b, u[i]) + 1 == d){
                return cout << "YES", 0;
            }
        }
	}
	cout << "NO";
}