#include<bits/stdc++.h>
#define taskname "1997B"
using namespace std;
const int lim = 4e5 + 5;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
string a[2];
int n, t_dfs, low[lim], num[lim], cnt[lim];
bitset<lim>cut_point;
vector<int>e[lim];
void dfs(int s, int p = -1){
	num[s] = low[s] = ++t_dfs;
	int cnt_child = 0;
	for(int& d : e[s]){
		if(d != p){
			if(num[d] == 0){
				dfs(d, s);
				minimize(low[s], low[d]);
				if(low[d] >= num[s] && p != -1){
					cut_point.set(s);
					cnt_child++;
				}
			}
			else{
				minimize(low[s], num[d]);
			}
		}
	}
	if(p == -1 && cnt_child > 1){
		cut_point.set(s);
	}
	if(cut_point.test(s)){
		cnt[cnt_child + int(p != -1) - 1]++;
	}
	else{
		cnt[0]++;
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		cin >> n >> a[0] >> a[1];
		a[0] = '#' + a[0];
		a[1] = '#' + a[1];
		for(int i = n << 1; i > 0; i--){
			e[i].clear();
			cut_point.reset(i);
		}
		for(int i = 1; i <= n; i++){
			if(a[0][i] == '.'){
				if(i > 1 && a[0][i - 1] == '.'){
					e[i].emplace_back(i - 1);
				}
				if(i < n && a[0][i + 1] == '.'){
					e[i].emplace_back(i + 1);
				}
				if(a[1][i] == '.'){
					e[i].emplace_back(i + n);
					e[i + n].emplace_back(i);
				}
			}
			if(a[1][i] == '.'){
				if(i > 1 && a[1][i - 1] == '.'){
					e[i + n].emplace_back(i + n - 1);
				}
				if(i < n && a[1][i + 1] == '.'){
					e[i + n].emplace_back(i + n + 1);
				}
			}
		}
		fill(num + 1, num + (n << 1) + 1, t_dfs = 0);
		fill(cnt + 1, cnt + (n << 1) + 1, 0);
		int iso = 0, cnt_scc = 0;
		for(int i = n << 1; i > 0; i--){
			if(a[i > n][i > n ? i - n : i] == '.' && num[i] == 0){
				int current_t_dfs = t_dfs;
				dfs(i);
				if(t_dfs - 1 == current_t_dfs){
					iso++;
				}
				cnt_scc++;
			}
		}
		if(cnt_scc > 4){
			cout << "0\n";
		}
		else if(cnt_scc == 4){
			cout << iso << "\n";
		}
		else if(cnt_scc == 3){
			cout << cnt[0] - iso << "\n";
		}
		else{
			cout << cnt[3 - cnt_scc] << "\n";
		}
	}
}