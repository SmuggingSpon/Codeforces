#include<bits/stdc++.h>
#define taskname "1207G"
using namespace std;
const int lim = 4e5 + 5;
struct Node{
	int link, go[26];
	Node(){
		memset(go, link = -1, sizeof(go));
	}
};
Node trn[lim], trq[lim];
int n, q, cnt_trn = 0, cnt_trq = 0, time_dfs = 0, sroot[lim], bit[lim], ans[lim], low[lim], tail[lim], qnode[lim];
vector<int>query[lim], g[lim], s_in_trn[lim];
void update(int p, int x){
	for(; p < lim; p += p & -p){
		bit[p] += x;
	}
}
int get(int p){
	int ans = 0;
	for(; p > 0; p -= p & -p){
		ans += bit[p];
	}
	return ans;
}
int add_letter(int u, char c){
	return trn[u].go[c] == -1 ? trn[u].go[c] = ++cnt_trn : trn[u].go[c];
}
int add_string(string& s){
	int root = 0;
	for(char& c : s){
		if(trq[root].go[c -= 97] == -1){
			trq[root].go[c] = ++cnt_trq; 
		}
		root = trq[root].go[c];
	}
	return root;
}
void dfs_1(int s){
	low[s] = ++time_dfs;
	for(int& d : g[s]){
		dfs_1(d);
	}
	tail[s] = time_dfs;
}
void dfs_2(int s, int sq){
	update(low[sq], 1);
	for(int& i : s_in_trn[s]){
		for(int& j : query[i]){
			ans[j] = get(tail[qnode[j]]) - get(low[qnode[j]] - 1);
		}
	}
	for(int i = 0; i < 26; i++){
		if(trn[s].go[i] != -1){
			dfs_2(trn[s].go[i], max(0, trq[sq].go[i]));
		}
	}
	update(low[sq], -1);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n;
	for(int i = 1; i <= n; i++){
		int t;
		cin >> t;
		if(t == 1){
			char c;
			cin >> c;
			sroot[i] = add_letter(0, c - 97);
		}
		else{
			int j;
			char c;
			cin >> j >> c;
			sroot[i] = add_letter(sroot[j], c - 97);
		}
		s_in_trn[sroot[i]].emplace_back(i);
	}
	cin >> q;
	for(int i = 0; i < q; i++){
		int j;
		string s;
		cin >> j >> s;
		query[j].emplace_back(i);
		qnode[i] = add_string(s);
	}
	queue<int>que;
	que.push(trq[0].link = 0);
	while(!que.empty()){
		int u = que.front();
		que.pop();
		for(int i = 0; i < 26; i++){
			int v = trq[u].go[i];
			if(v == -1){
				trq[u].go[i] = trq[trq[u].link].go[i];
			}
			else{
				if(trq[v].link == -1){
					trq[v].link = max(0, u == 0 ? 0 : trq[trq[u].link].go[i]);
				}
				que.push(v);
			}
		}
	}
	for(int i = 1; i <= cnt_trq; i++){
		g[trq[i].link].emplace_back(i);
	}
	dfs_1(0);
	memset(bit, 0, sizeof(bit));
	dfs_2(0, 0);
	for(int i = 0; i < q; i++){
		cout << ans[i] << "\n";
	}
}