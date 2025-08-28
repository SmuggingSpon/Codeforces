#include<bits/stdc++.h>
#define taskname "1175E"
using namespace std;
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
const int lim = 2e5 + 5;
const int LIM = 5e5 + 5;
pair<int, int>line[lim], st[LIM << 2];
int n, m, up[lim][18];
void update(int id, int l, int r, int p, pair<int, int>x){
	if(l == r){
		maximize(st[id], x);
		return;
	}
	int m = (l + r) >> 1;
	if(m < p){
		update(id << 1 | 1, m + 1, r, p, x);
	}
	else{
		update(id << 1, l, m, p, x);
	}
	st[id] = max(st[id << 1], st[id << 1 | 1]);
}
pair<int, int>get(int id, int l, int r, int u, int v){
	if(l > v || r < u){
		return make_pair(0, 0);
	}
	if(u <= l && v >= r){
		return st[id];
	}
	int m = (l + r) >> 1;
	return max(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cin >> n >> m;
	for(int i = (LIM << 2) - 1; i > 0; i--){
		st[i] = make_pair(0, 0);
	}
	for(int i = 1; i <= n; i++){
		cin >> line[i].first >> line[i].second;
		update(1, 0, LIM - 1, line[i].first, make_pair(line[i].second, i));
	}
	for(int i = 1; i <= n; i++){
		up[i][0] = get(1, 0, LIM - 1, line[i].first, line[i].second).second;
	}
	for(int j = 1; j < 18; j++){
		for(int i = 1; i <= n; i++){
			up[i][j] = up[up[i][j - 1]][j - 1];
		}
	}
	for(int _ = 0; _ < m; _++){
		int x, y;
		cin >> x >> y;
		int I = get(1, 0, LIM - 1, 0, x).second;
		if(I == 0){
			cout << "-1\n";
			continue;
		}
		if(line[I].second >= y){
			cout << "1\n";
			continue;
		}
		int ans = 0;
		for(int i = 17; i > -1; i--){
			if(line[up[I][i]].second < y){
				ans |= 1 << i;
				I = up[I][i];
			}
		}
		cout << (line[up[I][0]].second < y ? -1 : ans + 2) << "\n";
	}
}