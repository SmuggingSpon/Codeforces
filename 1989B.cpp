#include<bits/stdc++.h>
#define taskname "1989B"
using namespace std;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
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
		string a, b;
		cin >> a >> b;
		vector<vector<int>>p(a.size(), vector<int>(26, a.size()));
		p[int(a.size()) - 1][a.back() - 97] = int(a.size()) - 1;
		for(int i = int(a.size()) - 2; i > -1; i--){
			p[i] = p[i + 1];
			p[i][a[i] - 97] = i;
		}
		int ans = int(a.size() + b.size());
		for(int l = 0; l < b.size(); l++){
			int current = 0;
			for(int r = l; r < b.size() && current < a.size(); r++){
				if((current = p[current][b[r] - 97]) == a.size()){
					break;
				}
				minimize(ans, int(a.size()) + int(b.size()) - (r - l + 1));
				current++;
			}
		}
		cout << ans << "\n";
	}
}