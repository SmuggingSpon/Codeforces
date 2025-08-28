#include<bits/stdc++.h>
#define taskname "2039D"
using namespace std;
const int lim = 3e5 + 5;
template<class T>void maximize(T& a, T b){
	if(a < b){
		a = b;
	}
}
int I[lim];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	memset(I, 0, sizeof(I));
	for(int i = 1; i < lim; i++){
		for(int j = i << 1; j < lim; j += i){
			maximize(I[j], I[i] + 1);
		}
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, m;
		cin >> n >> m;
		vector<int>S(m);
		for(int& x : S){
			cin >> x;
		}
		if(*max_element(I + 1, I + n + 1) >= m){
			cout << "-1\n";
			continue;
		}
		reverse(S.begin(), S.end());
		for(int i = 1; i <= n; i++){
			cout << S[I[i]] << " ";
		}
		cout << "\n";
	}
}