#include<bits/stdc++.h>
#define taskname "2059D"
using namespace std;
const int INF = 2e9;
template<class T>bool minimize(T& a, T b){
	if(a > b){
		a = b;
		return true;
	}
	return false;
}
struct Data{
	int i, j, w;
	Data(){}
	Data(int _i, int _j, int _w) : i(_i), j(_j), w(_w) {}
	friend bool operator <(const Data a, const Data b){
		return a.w > b.w;
	}
};
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, s1, s2, m1, m2;
		cin >> n >> s1 >> s2 >> m1;
		vector<vector<int>>g1(n + 1), g2(n + 1);
		for(int i = 0; i < m1; i++){
			int u, v;
			cin >> u >> v;
			g1[u].emplace_back(v);
			g1[v].emplace_back(u);
		}
		cin >> m2;
		for(int i = 0; i < m2; i++){
			int u, v;
			cin >> u >> v;
			g2[u].emplace_back(v);
			g2[v].emplace_back(u);
		}
		for(int i = 1; i <= n; i++){
			sort(g1[i].begin(), g1[i].end());
			sort(g2[i].begin(), g2[i].end());
		}
		vector<vector<int>>d(n + 1, vector<int>(n + 1, INF));
		priority_queue<Data>pq;
		for(int i = 1; i <= n; i++){
			for(int& u : g1[i]){
				if(binary_search(g2[i].begin(), g2[i].end(), u)){
					pq.emplace(i, i, d[i][i] = 0);
					break;
				}
			}
		}
		while(!pq.empty()){
			auto [i, j, w] = pq.top();
			pq.pop();
			if(d[i][j] == w){
				int W = abs(i - j);
				for(int& u : g1[i]){
					for(int& v : g2[j]){
						if(minimize(d[u][v], w + W)){
							pq.emplace(u, v, d[u][v]);
						}
					}
				}
			}
		}
		cout << (d[s1][s2] == INF ? -1 : d[s1][s2]) << "\n";
	}
}