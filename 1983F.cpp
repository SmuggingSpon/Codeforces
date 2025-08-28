#include<bits/stdc++.h>
#define taskname "1983F"
using namespace std;
typedef long long ll;
const int INF = 2e9;
struct Node{
    int cnt, child[2];
    Node(){
        this->child[this->cnt = 0] = this->child[1] = -1;
    }
};
vector<Node>trie;
void insert_number(int x){
    trie[0].cnt++;
    for(int i = 29, root = 0; i > -1; i--){
        bool nxt = bool(1 << i & x);
        if(trie[root].child[nxt] == -1){
            trie[root].child[nxt] = trie.size();
            trie.emplace_back(Node());
        }
        trie[root = trie[root].child[nxt]].cnt++;
    }
}
void remove_number(int x){
    trie[0].cnt--;
    for(int i = 29, root = 0; i > -1; i--){
        trie[root = trie[root].child[(x >> i) & 1]].cnt--;
    }
}
int get_cnt(int root){
    return root == -1 ? 0 : trie[root].cnt;
}
int get_min(int x){
    if(trie[0].cnt == 0){
        return INF;
    }
    int ans = 0;
    for(int i = 29, root = 0; i > -1; i--){
        bool nxt = bool(1 << i & x);
        if(get_cnt(trie[root].child[nxt]) > 0){
            root = trie[root].child[nxt];
        }
        else{
            ans |= 1 << i;
            root = trie[root].child[!nxt];
        }
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
        int n, ans, low = 0, high = (1 << 30) - 1;
        ll k;
        cin >> n >> k;
        vector<int>a(n);
        for(int& x : a){
            cin >> x;
        }
        while(low <= high){
            int mid = (low + high) >> 1;
            trie.clear();
            trie.emplace_back(Node());
            ll cnt = (1LL * n * (n - 1)) >> 1LL;
            for(int l = 0, r = 0; r < n; insert_number(a[r++])){
                while(get_min(a[r]) <= mid){
                    remove_number(a[l++]);
                }
                cnt -= r - l;
            }
            if(cnt >= k){
                high = (ans = mid) - 1;
            }
            else{
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}