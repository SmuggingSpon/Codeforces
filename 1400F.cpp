#include<bits/stdc++.h>
#define taskname "1400F"
using namespace std;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
const int INF = 1e9;
string s;
int sum;
struct Node{
	int link, child[10], go[10];
	bool leaf;
	Node(){
		memset(this->child, this->link = -1, sizeof(child));
		memset(this->go, -1, sizeof(this->go));
		this->leaf = false;
	}
};
vector<Node>trie(1);
void insert_string(const string& s){
	int root = 0;
	for(const char& c : s){
		if(trie[root].child[c] == -1){
			trie[root].child[c] = trie.size();
			trie.emplace_back(Node());
		}
		root = trie[root].child[c];	
	}
	trie[root].leaf = true;
}
void generate(string s, int cnt){
	if(cnt == sum){
		bool can = true;
		for(int i = 0; i < s.size(); i++){
			for(int j = i, cur = 0; j < s.size(); j++){
				if((cur += s[j]) < sum && sum % cur == 0){
					can = false;
					break;
				}
			}
		}
		if(can){
			insert_string(s);
		}
		return;
	}
	for(int i = 2; i < 10 && cnt + i <= sum; i++){
		generate(s + char(i), cnt + i);
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> s >> sum;
	if(sum == 1){
		return cout << count(s.begin(), s.end(), '1'), 0;
	}
	generate("", 0);
	queue<int>q;
	q.push(0);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(trie[u].link == -1){
			trie[u].link = 0;
		}
		for(int i = 2; i < 10; i++){
			int v = trie[u].child[i];
			if(v != -1){
				q.push(trie[u].go[i] = v);
				if(u != 0){
					trie[v].link = trie[trie[u].link].go[i];
				}
			}
			else{
				trie[u].go[i] = trie[trie[u].link].go[i];
			}
		}
	}
	for(char& c : s){
		c -= 48;
	}
	vector<vector<int>>f(trie.size(), vector<int>(s.size(), -1));
	auto dp = [&] (auto&& self, int node, int pos) -> int{
		if(trie[node].leaf){
			return INF;
		}
		if(pos == s.size()){
			return 0;
		}	
		int& ans = f[node][pos];
		if(ans != -1){
			return ans;
		}
		ans = self(self, node, pos + 1) + 1;
		int x = trie[node].go[s[pos]];
		minimize(ans, self(self, x == -1 ? 0 : x, pos + 1));
		return ans;
	};
	cout << dp(dp, 0, 0);
}