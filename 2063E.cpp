#include<bits/stdc++.h>
#define taskname "2063E"
using namespace std;
typedef long long ll;
const int lim = 3e5 + 5;
struct Node{
	int cnt, child[2];
	ll sum;	
	Node(){
		this->cnt = this->sum = 0;
		this->child[0] = this->child[1] = -1;
	}
};
struct Trie{
	vector<Node>trie;
	Trie(){
		trie.emplace_back(Node());
	}
	void insert(int x){
		trie[0].cnt++;
		trie[0].sum += x;
		for(int i = 18, root = 0; i > -1; i--){
			bool nxt = bool(1 << i & x);
			if(trie[root].child[nxt] == -1){
				trie[root].child[nxt] = trie.size();
				trie.emplace_back(Node());
			}
			trie[root = trie[root].child[nxt]].cnt++;
			trie[root].sum += x;
		}
	}
	pair<int, ll>get(int node){
		return node == -1 ? make_pair(0, 0LL) : make_pair(trie[node].cnt, trie[node].sum);
	}
	pair<int, ll>under(int x){
		pair<int, ll>ans = make_pair(0, 0LL);
		for(int i = 18, root = 0; i > -1; i--){
			bool nxt = bool(1 << i & x);
			if(nxt){
				pair<int, ll>add = get(trie[root].child[!nxt]);
				ans.first += add.first;
				ans.second += add.second;
			}
			if((root = trie[root].child[nxt]) == -1){
				break;
			}
		}
		return ans;
	}
};
Trie t[lim];
vector<int>vertex[lim], g[lim];		
int n, h[lim];
ll ans;
void dfs(int s, int p = -1){
	for(int& d : g[s]){
		if(d != p){
			h[d] = h[s] + 1;
			dfs(d, s);
			if(vertex[s].size() < vertex[d].size()){
				swap(vertex[s], vertex[d]);
				swap(t[s], t[d]);
			}		
			for(int& I : vertex[d]){
				auto [cnt, sum_under] = t[s].under(h[I]);
				ans += ((sum_under - 1LL * cnt * h[s]) << 1LL) - cnt;
				ans += 2LL * (cnt = t[s].trie[0].cnt - cnt) * (h[I] - h[s]) - cnt;
			}
			for(int& I : vertex[d]){
				t[s].insert(h[I]);
				vertex[s].emplace_back(I);
			}
		}
	}
	t[s].insert(h[s]);
	vertex[s].emplace_back(s);
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
			t[i] = Trie();
			g[i].clear();
			vertex[i].clear();
		}
		for(int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		ans = 0;
		dfs(h[1] = 1);
		cout << ans << "\n";
	}
}