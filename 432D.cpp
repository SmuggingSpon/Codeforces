#include<bits/stdc++.h>
#define taskname "432D"
using namespace std;
const int lim = 1e5 + 5;
int f[lim], z[lim];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	string s;
	cin >> s;
	int n = s.size();
	s = '$' + s;
	vector<int>ans = {n};
	memset(f, 0, sizeof(f));
	f[n]++;
	for(int l = 0, r = 0, i = 2; i <= n; i++){
		if(r < i){
			l = r = i;
			while(r <= n && s[r] == s[r - i + 1]){
				r++;
			}
			z[i] = r-- - l;
		}
		else if(z[i - l + 1] < r - i + 1){
			z[i] = z[i - l + 1];
		}
		else{
			while(r <= n && s[r] == s[r - i + 1]){
				r++;
			}
			z[i] = r-- - (l = i);
		}
		if(i + z[i] - 1 == n){
			ans.emplace_back(z[i]);
		}
		f[z[i]]++;
	}
	for(int i = n - 1; i > 0; i--){
		f[i] += f[i + 1];
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for(int& x : ans){
		cout << x << " " << f[x] << "\n";
	}
}