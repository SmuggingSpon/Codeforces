#include<bits/stdc++.h>
#define taskname "1202E"
using namespace std;
typedef long long ll;
const int lim = 2e5 + 5;
string t, s[lim];
int n, cnt[lim];
struct Node{
	int link, h, cnt, go[26];
	vector<int>p;
	Node(){
		memset(this->go, this->link = -1, sizeof(this->go));
		this->cnt = 0;
	}
};
vector<Node>trie(1);
void insert_string(string& s){
	int root = 0;
	for(char& c : s){
		if(trie[root].go[c -= 97] == -1){
			trie.emplace_back(Node());
			trie[trie[root].go[c] = int(trie.size()) - 1].h = trie[root].h + 1;
		}
		root = trie[root].go[c];
	}
	trie[root].cnt++;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	trie[0].h = 0;
	cin >> t >> n;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
		insert_string(s[i]);
	}
	queue<int>q;
	q.push(0);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(trie[u].link == -1){
			trie[u].link = 0;
		}
		for(int i = 0; i < 26; i++){
			int v = trie[u].go[i];
			if(v != -1){
				q.push(trie[u].go[i] = v);
				trie[v].link = (u == 0 ? 0 : trie[trie[u].link].go[i]);
			}
			else{
				trie[u].go[i] = trie[trie[u].link].go[i];
			}
		}
	}
	for(int i = 0, root = 0; i < t.size(); i++){
		if((root = trie[root].go[t[i] -= 97]) == -1){
			root = 0;
		}		
		trie[root].p.emplace_back(i);
	}
	memset(cnt, 0, sizeof(cnt));
	vector<int>p(trie.size());
	iota(p.begin(), p.end(), 0);
	sort(p.begin(), p.end(), [&] (int i, int j) -> bool{
		return trie[i].h > trie[j].h;
	});
	for(int& i : p){
		if(trie[i].cnt > 0){
			for(int& j : trie[i].p){
				cnt[j - trie[i].h + 1] += trie[i].cnt;	
			}
		}
		int suf_link = trie[i].link;
		if(suf_link != 0){
			if(trie[suf_link].p.size() < trie[i].p.size()){
				swap(trie[suf_link].p, trie[i].p);
			}
			for(int& j : trie[i].p){
				trie[suf_link].p.emplace_back(j);
			}
		}
		trie[i].p.clear();
	}
	ll ans = 0;
	for(int i = 0, root = 0; i < t.size(); i++){
		if((root = trie[root].go[t[i]]) == -1){
			root = 0;
		}		
		trie[root].p.emplace_back(i);
	}
	for(int& i : p){
		if(trie[i].cnt > 0){
			for(int& j : trie[i].p){
				ans += 1LL * cnt[j + 1] * trie[i].cnt;	
			}
		}
		int suf_link = trie[i].link;
		if(suf_link != 0){
			if(trie[suf_link].p.size() < trie[i].p.size()){
				swap(trie[suf_link].p, trie[i].p);
			}
			for(int& j : trie[i].p){
				trie[suf_link].p.emplace_back(j);
			}
		}
	}
	cout << ans;
}