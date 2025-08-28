#include<bits/stdc++.h>
#define taskname "1582F1"
using namespace std;
const int lim = 512;
bitset<lim>can_make, g[lim];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int n;
	cin >> n;
	for(int i = 1; i < lim; i++){
		g[i].set(0);
	}
	for(int _ = 0; _ < n; _++){
		int x;
		cin >> x;
		can_make.reset();
		for(int i = 0; i < lim; i++){
			if(g[x].test(i)){
				can_make.set(x ^ i);
			}
		}
		for(int i = x + 1; i < lim; i++){
			g[i] |= can_make;
		}
	}
	can_make.reset();
	for(int i = 1; i < lim; i++){
		can_make |= g[i];
	}
	cout << can_make.count() << "\n";
	for(int i = 0; i < lim; i++){
		if(can_make.test(i)){
			cout << i << " ";
		}
	}
}