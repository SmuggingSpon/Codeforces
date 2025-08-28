#include<bits/stdc++.h>
#define taskname "1927D"
using namespace std;
const int lim = 2e5 + 5;
int n, q, a[lim], loga_2[lim], spt_max[lim][18], spt_min[lim][18];
int index_max(int i, int j){
	return a[i] > a[j] ? i : j; 
}
int index_min(int i, int j){
	return a[i] < a[j] ? i : j;
}
int get_max(int l, int r){
	int k = loga_2[r - l + 1];
	return index_max(spt_max[l][k], spt_max[r - (1 << k) + 1][k]);
}
int get_min(int l, int r){
	int k = loga_2[r - l + 1];
	return index_min(spt_min[l][k], spt_min[r - (1 << k) + 1][k]);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	loga_2[0] = -1;
	for(int i = 1; i < lim; i++){
		loga_2[i] = loga_2[i >> 1] + 1;
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[spt_max[i][0] = spt_min[i][0] = i];
		}
		for(int j = 1; j < 18; j++){
			for(int i = 1; i + (1 << j) - 1 <= n; i++){
				spt_max[i][j] = index_max(spt_max[i][j - 1], spt_max[i + (1 << (j - 1))][j - 1]);
				spt_min[i][j] = index_min(spt_min[i][j - 1], spt_min[i + (1 << (j - 1))][j - 1]);
			}
		}
		cin >> q;
		for(int _q = 0; _q < q; _q++){
			int l, r;
			cin >> l >> r;
			int i = get_max(l, r), j = get_min(l, r);
			if(a[i] == a[j]){
				cout << "-1 -1\n";
			}
			else{
				cout << i << " " << j << "\n";
			}
		}
		cout << "\n";
	}
}