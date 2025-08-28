#include<bits/stdc++.h>
#define taskname "1000F"
using namespace std;
const int lim = 5e5 + 5;
const int SIZE = 750;
const int CNT_BLOCK = lim / SIZE + 1;
int n, q, a[lim], block_id[lim], cnt[lim], S[CNT_BLOCK], ans[lim];
void add(int x){
	if(++cnt[x] == 1){
		S[block_id[x]]++;
	}
	else if(cnt[x] == 2){
		S[block_id[x]]--;
	}
}
void sub(int x){
	if(--cnt[x] == 0){
		S[block_id[x]]--;
	}
	else if(cnt[x] == 1){
		S[block_id[x]]++;
	}
}
struct Query{
	int l, r, i;
	bool operator <(const Query& other){
		return block_id[this->l] < block_id[other.l] || (block_id[this->l] == block_id[other.l] && ((block_id[this->l] & 1) ? this->r > other.r : this->r< other.r));
	}
};
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	for(int i = 1; i < lim; i++){
		block_id[i] = i / SIZE;
	}
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	cin >> q;
	vector<Query>query(q);
	for(int i = 0; i < q; i++){
		cin >> query[query[i].i = i].l >> query[i].r;
	}
	sort(query.begin(), query.end());
	int L = 1, R = 0;
	memset(cnt, 0, sizeof(cnt));
	memset(S, 0, sizeof(S));
	memset(ans, 0, sizeof(ans));
	for(auto& [l, r, I] : query){
		while(L < l){
			sub(a[L++]);
		}
		while(L > l){
			add(a[--L]);
		}
		while(R < r){
			add(a[++R]);
		}
		while(R > r){
			sub(a[R--]);
		}
		for(int i = 0; i < CNT_BLOCK; i++){
			if(S[i] > 0){
				for(int j = i * SIZE; true; j++){
					if(cnt[j] == 1){
						ans[I] = j;
						break;
					}
				}
				break;
			}
		}
	}
	for(int i = 0; i < q; i++){
		cout << ans[i] << "\n";
	}
}