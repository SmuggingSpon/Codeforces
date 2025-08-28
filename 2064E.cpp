#include<bits/stdc++.h>
#define taskname "2064E"
using namespace std;
const int mod = 998244353;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n;
		cin >> n;
		vector<int>parent(n + 1), siz(n + 1, 1), p(n + 1), c(n + 1);
		auto find_set = [&] (int N){
			while(N != parent[N]){
				N = parent[N] = parent[parent[N]];
			}	
			return N;
		};
		auto merge = [&] (int a, int b){
			if((a = find_set(a)) != (b = find_set(b))){
				if(siz[a] < siz[b]){
					swap(a, b);
				}
				siz[parent[b] = a] += siz[b];
			}
		};
		for(int i = 1; i <= n; i++){
			cin >> p[i];
		}
		for(int i = 1; i <= n; i++){
			cin >> c[i];
		}
		vector<int>nxt(n + 1), prev(n + 1);
		iota(nxt.begin(), nxt.end(), 1);
		iota(prev.begin(), prev.end(), -1);
		prev[1] = nxt[n] = -1;
		iota(parent.begin(), parent.end(), 0);
		for(int i = 2; i <= n; i++){
			if(c[i] == c[i - 1]){
				merge(i, i - 1);
			}
		}	
		vector<int>I(n);
		iota(I.begin(), I.end(), 1);
		sort(I.begin(), I.end(), [&] (int i, int j) -> bool{
			return p[i] < p[j];
		});
		int ans = 1;
		for(int& i : I){
			int left = prev[i], right = nxt[i];
			if(left == -1 && right == -1){
				break;
			}
			if(left == -1){
				if(c[i] == c[right]){
					ans = 1LL * ans * siz[find_set(right)] % mod;
				}
				siz[find_set(i)]--;
				prev[right] = -1;
			}
			else if(right == -1){
				if(c[i] == c[left]){
					ans = 1LL * ans * siz[find_set(left)] % mod;
				}
				siz[find_set(i)]--;
				nxt[left] = -1;
			}
			else{
				nxt[left] = nxt[i];
				prev[right] = prev[i];
				if(c[i] == c[left] && c[i] == c[right]){
					merge(i, left);
					merge(i, right);
					ans = 1LL * ans * siz[find_set(i)]-- % mod;
				}
				else if(c[i] == c[left]){
					merge(i, left);
					ans = 1LL * ans * siz[find_set(i)]-- % mod;
				}
				else if(c[i] == c[right]){
					merge(i, right);
					ans = 1LL * ans * siz[find_set(i)]-- % mod;
				}
				else if(c[left] == c[right]){
					merge(left, right);
				}
			}
		}
		cout << ans << "\n";
	}
}