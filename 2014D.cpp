#include<bits/stdc++.h>
#define taskname "2014D"
using namespace std;
template<class T>bool minimize(T& a, T b){
	if(a > b){
		a = b;
		return true;
	}
	return false;
}
template<class T>bool maximize(T& a, T b){
	if(a < b){
		a = b;
		return true;
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, d, k, current_ans = 0;
		cin >> n >> d >> k;
		pair<int, int>brother = make_pair(-1, -1), mother = make_pair(INT_MAX, -1);
		vector<int>add(n + 1, 0), sub(n + 2, 0);
		for(int i = 0; i < k; i++){
			int l, r;
			cin >> l >> r;
			if(l <= d){
				current_ans++;
			}
			else{
				add[l]++;
			}
			sub[r + 1]++;
		}
		if(maximize(brother.first, current_ans)){
			brother.second = 1;
		}
		if(minimize(mother.first, current_ans)){
			mother.second = 1;
		}
		for(int r = d + 1; r <= n; r++){
			if(maximize(brother.first, current_ans += add[r] - sub[r - d + 1])){
				brother.second = r - d + 1;
			}
			if(minimize(mother.first, current_ans)){
				mother.second = r - d + 1;
			}
		}
		cout << brother.second << " " << mother.second << "\n";
	}
}