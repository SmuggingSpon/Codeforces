#include<bits/stdc++.h>
#define taskname "471D"
using namespace std;
const int INF = 2e9;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	vector<int>a, b;
	int n, w, temp;
	cin >> n >> w >> temp;
	if(w == 1){
		return cout << n, 0;
	}
	for(int i = 1; i < n; i++){
		int x;
		cin >> x;
		b.emplace_back(x - temp);
		temp = x;
	}
	cin >> temp;
	for(int i = 1; i < w; i++){
		int x;
		cin >> x;
		a.emplace_back(x - temp);
		temp = x;
	}
	a.emplace_back(INF);
	for(int& x : b){
		a.emplace_back(x);
	}
	int ans = 0;
	vector<int>z(n = a.size());
	for(int i = 1, l = 0, r = 0; i < n; i++){
		if(r < i){
			l = r = i;
			while(r < n && a[r] == a[r - i]){
				r++;
			}
			z[i] = r-- - l;
		}
		else if(z[i - l] < r - i + 1){
			z[i] = z[i - l];
		}
		else{
			while(r < n && a[r] == a[r - i]){
				r++;
			}
			z[i] = r-- - (l = i);
		}
		if(z[i] == w - 1){
			ans++;
		}
	}
	cout << ans;
}