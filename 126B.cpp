#include<bits/stdc++.h>
#define taskname "126B"
using namespace std;
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	string s;
	cin >> s;
	int n = s.size(), allow = -1, ans_length = -1;
	vector<int>z(n);
	for(int i = 1, l = 0, r = 0; i < n; i++){
		if(r < i){
			l = r = i;
			while(r < n && s[r] == s[r - i]){
				r++;
			}
			z[i] = r-- - l;
		}
		else if(z[i - l] < r - i + 1){
			z[i] = z[i - l];
		}
		else{
			while(r < n && s[r] == s[r - i]){
				r++;
			}
			z[i] = r-- - (l = i);
		}
		if(i < n){
			maximize(allow, z[i] - int(i + z[i] == n));
		}
	}
	for(int i = 1; i < n; i++){
		if(z[i] <= allow && i + z[i] == n){
			maximize(ans_length, z[i]);
		}
	}
	cout << (allow == -1 || ans_length == -1 ? "Just a legend" : s.substr(0, ans_length));
}