#include<bits/stdc++.h>
#define taskname "1976D"
using namespace std;
typedef long long ll;
const int lim = 2e5 + 5;
int log_v[lim], spt[lim][18];
vector<int>p[lim];
int get(int l, int r){
	int k = log_v[r - l + 1];
	return max(spt[l][k], spt[r - (1 << k) + 1][k]);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	log_v[0] = -1;
	for(int i = 1; i < lim; i++){
		log_v[i] = log_v[i >> 1] + 1;
	}
	for(int _ = spt[0][0] = 0; _ < _t; _++){
		string s;
		cin >> s;
		int n = s.size();
		s = '$' + s;
		p[0].clear();
		for(int i = 1; i <= n; i++){
			p[i].clear();
			spt[i][0] = spt[i - 1][0];
			if(s[i] == '('){
				spt[i][0]++;
			}
			else{
				spt[i][0]--;
			}
			p[spt[i][0]].emplace_back(i);
		}
		for(int j = 1; j < 18; j++){
			for(int i = 1; i + (1 << j) - 1 <= n; i++){
				spt[i][j] = max(spt[i][j - 1], spt[i + (1 << (j - 1))][j - 1]);
			}
		}
		ll ans = 0;
		for(int i = 0; i < n; i++){
			int low = i + 1, high = n, pos = -1;
			while(low <= high){
				int mid = (low + high) >> 1;
				if((spt[i][0] << 1) - get(i + 1, mid) > -1){
					low = (pos = mid) + 1;
				}
				else{
					high = mid - 1;
				}
			}
			if(pos != -1){
				ans += upper_bound(p[spt[i][0]].begin(), p[spt[i][0]].end(), pos) - lower_bound(p[spt[i][0]].begin(), p[spt[i][0]].end(), i + 1);
			}
		}
		cout << ans << "\n";
	}
}