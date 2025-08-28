#include<bits/stdc++.h>
#define taskname "617E"
using namespace std;
typedef long long ll;
const int lim = 1e5 + 5;
const int LIM = 1 << 20;
const int INF = 2e9;
const int SIZE = 300;
int n, m, k, L = 0, R = -1, cnt[LIM], a[lim];
ll current = 0, ans[lim];
struct Query{
    int l, r, i;
    bool operator <(const Query& other){
        int I = this->l / SIZE, J = other.l / SIZE;
        return I < J || (I == J && this->r < other.r);
    }
};
Query query[lim];
void add(int x){
    current += cnt[x ^ k];
    cnt[x]++;
}
void sub(int x){
    cnt[x]--;
    current -= cnt[x ^ k];
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    cin >> n >> m >> k;
    memset(cnt, a[0] = 0, sizeof(cnt));
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] ^= a[i - 1];
    }
    for(int i = 0; i < m; i++){
        cin >> query[query[i].i = i].l >> query[i].r;
    }
    sort(query, query + m);
    for(int i = 0; i < m; i++){
        int l = query[i].l - 1, r = query[i].r;
        while(R < r){
            add(a[++R]);
        }
        while(R > r){
            sub(a[R--]);
        }
        while(L > l){
            add(a[--L]);
        }
        while(L < l){
            sub(a[L++]);
        }
        ans[query[i].i] = current;
    }
    for(int i = 0; i < m; i++){
        cout << ans[i] << "\n";
    }
}