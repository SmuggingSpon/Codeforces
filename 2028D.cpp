#include<bits/stdc++.h>
#define taskname "2028D"
using namespace std;
template<class T>bool maximize(T& a, T b){
	if(a < b){
		a = b;
		return true;
	}
	return false;
}
const int lim = 2e5 + 5;
const char OPE[3] = {'q', 'k', 'j'};
struct Data{
	int a[3];
};
Data a[lim];
pair<int, char>trace[lim];
pair<int, int>current[3];
void update_current(int i){
	for(int j = 0; j < 3; j++){
		if(maximize(current[j].first, a[i].a[j])){
			current[j].second = i;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	trace[1] = make_pair(0, '#');
	for(int _ = 0; _ < _t; _++){
		int n;
		cin >> n;
		for(int i = 0; i < 3; i++){
			for(int j = 1; j <= n; j++){
				int x;
				cin >> x;
				a[j].a[i] = x;
			}
		}
		for(int i = 0; i < 3; i++){
			current[i] = make_pair(a[1].a[i], 1);
		}
		for(int i = 2; i <= n; i++){
			bool can = false;
			for(int j = 0; j < 3; j++){
				if(a[i].a[j] < current[j].first){
					trace[i] = make_pair(current[j].second, OPE[j]);
					update_current(i);
					can = true;
					break;
				}
			}
			if(!can){
				trace[i] = make_pair(-1, '#');
			}
		}
		if(trace[n].first == -1){
			cout << "NO\n";
			continue;
		}
		vector<pair<int, char>>ans;
		int x = n;
		while(x != 1){
			ans.emplace_back(x, trace[x].second);
			x = trace[x].first;
		}
		cout << "YES\n" << ans.size() << "\n";
		for(int i = int(ans.size()) - 1; i > -1; i--){
			cout << ans[i].second << " " << ans[i].first << "\n";
		}
	}
}