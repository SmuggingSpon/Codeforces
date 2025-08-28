#include<bits/stdc++.h>
#define taskname "963D"
using namespace std;
const int lim = 1e5 + 5;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
vector<tuple<string, int, int>>query[lim];
int q, ans[lim];
vector<int>p[lim];
string s;
struct Node{
	int link, query_index, child[26], go[26];
	Node(){
		memset(this->child, this->link = this->query_index = -1, sizeof(this->child));
		memset(this->go, -1, sizeof(this->go));
	}	
};
vector<Node>trie;
void insert_string(string& s, int query_index){
	int root = 0;
	for(char& c : s){
		if(trie[root].child[c -= 97] == -1){
			trie[root].child[c] = trie.size();
			trie.emplace_back(Node());
		}
		root = trie[root].child[c];
	}
	trie[root].query_index = query_index;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> s >> q;
	for(char& c : s){
		c -= 97;
	}
	for(int i = 0; i < q; i++){
		string m;
		int k;
		cin >> k >> m;
		query[m.size()].emplace_back(m, k, i);
	}
	memset(ans, 0x0f, sizeof(ans));
	for(int len = 1; len <= s.size(); len++){
		if(!query[len].empty()){
			trie.clear();
			trie.emplace_back(Node());
			for(auto& [m, k, i] : query[len]){
				insert_string(m, i);
			}
			queue<int>Q;
			Q.push(0);
			while(!Q.empty()){
				int u = Q.front();
				Q.pop();
				if(trie[u].link == -1){
					trie[u].link = 0;
				}
				for(int i = 0; i < 26; i++){
					int v = trie[u].child[i];
					if(v != -1){
						Q.push(trie[u].go[i] = v);
						if(u != 0){
							trie[v].link = trie[trie[u].link].go[i];
						}
					}
					else{
						trie[u].go[i] = trie[trie[u].link].go[i];
					}
				}
			}
			int root = 0;
			for(int i = 0; i < s.size(); i++){
				if((root = trie[root].go[s[i]]) == -1){
					root = 0;
				}
				if(trie[root].query_index != -1){
					p[trie[root].query_index].emplace_back(i);
				}
			}
			for(auto& [m, k, i] : query[len]){
				for(int j = k - 1; j < p[i].size(); j++){
					minimize(ans[i], p[i][j] - p[i][j - k + 1]);
				}
				ans[i] += len;
			}
		}
	}
	for(int i = 0; i < q; i++){
		cout << (ans[i] > s.size() ? -1 : ans[i]) << "\n";
	}
}