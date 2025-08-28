#include<bits/stdc++.h>
#define taskname "2093G"
using namespace std;
template<class T>void minimize(T& a, T b){
    if(a > b){
        a = b;
    }
}
struct Node{
    int cnt, child[2];
    Node(){
        this->child[this->cnt = 0] = this->child[1] = -1;
    };
};
vector<Node>trie;
void insert_number(int x){
    for(int i = 30, root = 0; i > -1; i--){
        bool nxt = (x >> i & 1);
        if(trie[root].child[nxt] == -1){
            trie[root].child[nxt] = trie.size();
            trie.emplace_back(Node());
        }
        trie[root = trie[root].child[nxt]].cnt++;
    }
}
void remove_number(int x){
    for(int i = 30, root = 0; i > -1; i--){
        trie[root = trie[root].child[x >> i & 1]].cnt--; 
    }
}
bool exist(int id){
    return id != -1 && trie[id].cnt > 0;
}
int find_max(int x){
    int ans = 0;
    for(int i = 30, root = 0; i > -1; i--){
        bool n_opt = (x >> i & 1);
        if(exist(trie[root].child[!n_opt])){
            n_opt = !n_opt;
            ans |= 1 << i;
        }
        root = trie[root].child[n_opt];
    }
    return ans;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    int _t;
    cin >> _t;
    for(int _ = 0; _ < _t; _++){
        int n, k;
        cin >> n >> k;
        vector<int>a(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        if(k == 0){
            cout << "1\n";
            continue;
        }
        trie.assign(1, Node());
        int ans = n + 1;
        for(int r = 1, l = 1; r <= n; r++){
            insert_number(a[r]);
            while(find_max(a[r]) >= k){
                remove_number(a[l++]);
            }
            if(l > 1){
                minimize(ans, r - l + 2);
            }
        }
        cout << (ans == n + 1 ? -1 : ans) << "\n";
    }
}