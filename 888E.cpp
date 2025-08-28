#include<bits/stdc++.h>
#define taskname "888E"
using namespace std;
typedef long long ll;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
const int lim = 3e5 + 5;
const int INF = 2e9;
struct Node{
	int child[2];
	Node(){
		this->child[0] = this->child[1] = -1;
	}	
};
struct Trie{
	vector<Node>trie;
	Trie(){
		trie.emplace_back(Node());
	}
	void insert(int x){
		for(int i = 29, root = 0; i > -1; i--){
			bool nxt = bool(1 << i & x);
			if(trie[root].child[nxt] == -1){
				trie[root].child[nxt] = trie.size();
				trie.emplace_back(Node());
			}
			root = trie[root].child[nxt];
		}
	}
	int get_min(int x){
		int ans = 0;
		for(int i = 29, root = 0; i > -1; i--){
			bool nxt = bool(1 << i & x);
			if(trie[root].child[nxt] != -1){
				root = trie[root].child[nxt];
			}
			else{
				root = trie[root].child[!nxt];
				ans |= 1 << i;
			}
		}
		return ans;
	}
};
int n, a[lim];
ll solve(int bit, vector<int>p){
	if(bit == -1 || p.size() < 2){
		return 0;
	}
	vector<int>p0, p1;
	for(int& i : p){
		if(1 << bit & a[i]){
			p1.emplace_back(i);
		}
		else{
			p0.emplace_back(i);
		}
	}
	ll ans = solve(bit - 1, p0) + solve(bit - 1, p1);
	if(!p0.empty() && !p1.empty()){
		Trie t;
		for(int& i : p0){
			t.insert(a[i]);
		}
		int add = INF;
		for(int& i : p1){
			minimize(add, t.get_min(a[i]));
		}
		ans += add;
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int>p(n);
	iota(p.begin(), p.end(), 0);
	cout << solve(29, p);
}