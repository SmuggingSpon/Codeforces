#include<bits/stdc++.h>
#define taskname "60D"
using namespace std;
const int LIM = 1e7 + 1;
int n, ans = 0, p[LIM];
int find_set(int n){
	return n == p[n] ? n : p[n] = find_set(p[n]);
}
void merge(int a, int b){
	p[find_set(a)] = find_set(b);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	memset(p, 0, sizeof(p));
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		p[x] = x;
	}
	for(int i = 1; i * i < LIM; i++){
		for(int j = i + 1; ((i * j) << 1) < LIM && j * j - i * i < LIM; j++){
			int x = (i * j) << 1, y = j * j - i * i;
			if(__gcd(x, y) == 1){
				if(p[x] != 0 && p[y] != 0){
					merge(x, y);
				}
				if(((y = i * i + j * j) < LIM) && p[x] != 0 && p[y] != 0){
					merge(x, y);
				}
				if(y < LIM && p[x = j * j - i * i] != 0 && p[y] != 0){
					merge(x, y);
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i < LIM; i++){
		if(p[i] == i){
			ans++;
		}
	}
	cout << ans;
}