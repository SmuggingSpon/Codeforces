#include<bits/stdc++.h>
#define taskname "2048F"
using namespace std;
typedef long long ll;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
const int lim = 2e5 + 5;
const ll INF = 2e18;
int n, log_v[lim];
ll a[lim];
pair<ll, int>spt_b[lim][18];
pair<ll, int>get_min_b(int l, int r){
	int k = log_v[r - l + 1];
	return min(spt_b[l][k], spt_b[r - (1 << k) + 1][k]);
}
vector<ll>solve(int l, int r){
	vector<ll>ans(1, 1);
	if(l > r){
		return ans;
	}
	if(l == r){
		ans[0] = a[l];
		while(ans.back() > 1){
			ans.emplace_back((ans.back() - 1) / spt_b[l][0].first + 1);
		}
		return ans;
	}
	int P = get_min_b(l, r).second;
	vector<ll>left = solve(l, P - 1), right = solve(P + 1, r);
	ans.assign(65, INF);
	for(int i = 0, p = 0; i < left.size(); i++){
		while(right[p] > left[i]){
			p++;
		}
		if(i + p > 64){
			break;
		}
		minimize(ans[i + p], max(left[i], a[P]));
	}
	for(int i = 0, p = 0; i < right.size(); i++){
		while(left[p] > right[i]){
			p++;
		}
		if(i + p > 64){
			break;
		}
		minimize(ans[i + p], max(right[i], a[P]));
	}
	for(int i = 1; i < 65; i++){
		minimize(ans[i], (ans[i - 1] - 1) / spt_b[P][0].first + 1);
	}
	while(ans.size() > 1 && ans[int(ans.size()) - 2] == 1){
		ans.pop_back();
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	log_v[0] = -1;
	for(int i = 1; i < lim; i++){
		log_v[i] = log_v[i >> 1] + 1;
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1; i <= n; i++){
			cin >> spt_b[spt_b[i][0].second = i][0].first;
		}
		for(int j = 1; j < 18; j++){
			for(int i = 1; i + (1 << j) - 1 <= n; i++){
				spt_b[i][j] = min(spt_b[i][j - 1], spt_b[i + (1 << (j - 1))][j - 1]);
			}
		}
		cout << int(solve(1, n).size()) - 1 << "\n";
	}
}