#include<bits/stdc++.h>
#define taskname "375D"
using namespace std;
const int lim = 1e5 + 5;
struct Node{
	int cnt, child[2];
	Node(){
		this->child[this->cnt = 0] = this->child[1] = -1;
	}		
};
struct Trie{
	vector<Node>trie;
	Trie(){
		trie.emplace_back(Node());
	}
	void insert(int x){
		for(int i = 16, root = 0; i > -1; i--){
			bool nxt = bool(1 << i & x);
			if(trie[root].child[nxt] == -1){
				trie[root].child[nxt] = trie.size();
				trie.emplace_back(Node());
			}
			trie[root = trie[root].child[nxt]].cnt++;
		}
	}
	void remove(int x){
		for(int i = 16, root = 0; i > -1; i--){
			trie[root = trie[root].child[bool(1 << i & x)]].cnt--;
		}
	}
	int upper(int x){
		int ans = 0;
		for(int i = 16, root = 0; i > -1; i--){
			bool nxt = bool(1 << i & x);
			if(!nxt){
				int node = trie[root].child[1];
				if(node != -1){
					ans += trie[node].cnt;
				}
			}
			if((root = trie[root].child[nxt]) == -1){
				break;
			}
		}
		return ans;
	}
};
Trie t[lim];
int n, q, a[lim], ans[lim];
vector<int>g[lim];
map<int, int>cnt[lim];
vector<pair<int, int>>query[lim];
void dfs(int s, int p = -1){
	t[s].insert(++cnt[s][a[s]]);
	for(int& d : g[s]){
		if(d != p){
			dfs(d, s);
			if(cnt[s].size() < cnt[d].size()){
				swap(t[s], t[d]);
				swap(cnt[s], cnt[d]);
			}
			for(auto& [c, v] : cnt[d]){
				if(cnt[s][c] > 0){
					t[s].remove(cnt[s][c]);
				}
				t[s].insert(cnt[s][c] += v);
			}
		}
	}
	for(auto& [k, i] : query[s]){
		ans[i] = t[s].upper(k);
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	for(int i = 0; i < q; i++){
		int v, k;
		cin >> v >> k;
		query[v].emplace_back(--k, i);
	}
	dfs(1);
	for(int i = 0; i < q; i++){
		cout << ans[i] << "\n";
	}
}