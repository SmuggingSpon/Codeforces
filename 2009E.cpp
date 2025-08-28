#include<bits/stdc++.h>
#define taskname "2009E"
using namespace std;
typedef long long ll;
int l, r;
ll sum(int l, int r){
	return (1LL * (ll(l) + r) * (r - l + 1)) >> 1LL;
}
ll get(int mid){
	return sum(l, mid) - sum(mid + 1, r);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		cin >> r >> l;
		int low = l, high = (r += l - 1), p;
		while(low <= high){
			int mid = low + ((high - low) >> 1);
			if(get(mid) < 0){
				low = (p = mid) + 1;
			}
			else{
				high = mid - 1;
			}
		}
		cout << min(-get(p), get(p + 1)) << "\n";
	}
}