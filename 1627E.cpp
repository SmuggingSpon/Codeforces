#include<bits/stdc++.h>
#define taskname "1627E"
using namespace std;
typedef long long ll;
const ll INF = 1e18;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
struct Data{
	int c, d, w;
	Data(){}
	Data(int c, int d, int w){
		this->c = c;
		this->d = d;
		this->w = w;
	}
	bool operator <(const Data other){
		return this->w < other.w;
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
		int n, m, k;
		cin >> n >> m >> k;
		vector<int>x(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> x[i];
		}
		map<pair<int, int>, ll>dp;
		map<pair<int, int>, vector<Data>>g;
		vector<vector<int>>vertex(n + 1, vector<int>(1, -1));
		for(int i = 0; i < k; i++){
			int a, b, c, d, h;
			cin >> a >> b >> c >> d >> h;
			vertex[a].push_back(b);
			vertex[c].push_back(d);
			g[make_pair(a, b)].push_back(Data(c, d, h));
			dp[make_pair(a, b)] = dp[make_pair(c, d)] = INF;
		}
		vertex[1].push_back(1);
		vertex[n].push_back(m);
		dp[make_pair(1, 1)] = 0;
		dp[make_pair(n, m)] = INF;
		for(int i = 1; i <= n; i++){
			if(vertex[i].size() > 1){
				sort(vertex[i].begin(), vertex[i].end());
				ll min_value = dp[make_pair(i, vertex[i][1])] - 1LL * vertex[i][1] * x[i];
				for(int j = 2; j < vertex[i].size(); j++){
					int current = vertex[i][j];
					if(current != vertex[i][j - 1]){
						minimize(dp[make_pair(i, current)], min_value + 1LL * current * x[i]);
						minimize(min_value, dp[make_pair(i, current)] - 1LL * current * x[i]);
					}
				}
				min_value = dp[make_pair(i, vertex[i].back())] + 1LL * vertex[i].back() * x[i];
				for(int j = int(vertex[i].size()) - 2; j > 0; j--){
					int current = vertex[i][j];
					if(current != vertex[i][j + 1]){
						minimize(dp[make_pair(i, current)], min_value - 1LL * current * x[i]);
						minimize(min_value, dp[make_pair(i, current)] + 1LL * current * x[i]);
					}
				}
				for(int j = 1; j < vertex[i].size(); j++){
					int current = vertex[i][j];
					if(current != vertex[i][j - 1]){
						for(vector<Data>::iterator it = g[make_pair(i, current)].begin(); it != g[make_pair(i, current)].end(); it++){
							Data edge = *it;
							minimize(dp[make_pair(edge.c, edge.d)], dp[make_pair(i, current)] - edge.w);
						}
					}
				}
			}
		}
		if(dp[make_pair(n, m)] > ll(1e16)){
			cout << "NO ESCAPE\n";
			continue;
		}
		cout << dp[make_pair(n, m)] << "\n";
	}
}