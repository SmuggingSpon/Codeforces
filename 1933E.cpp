#include<bits/stdc++.h>
#define taskname "1933E"
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n;
		cin >> n;
		vector<ll>a(n + 1);
		a[0] = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			a[i] += a[i - 1];
		}
		int q;
		cin >> q;
		for(int _q = 0; _q < q; _q++){
			int l, u;
			cin >> l >> u;
			int low = l, high = n, pos = l;
			while(low <= high){
				int mid = (low + high) >> 1;
				if(a[mid] - a[l - 1] <= u){
					low = (pos = mid) + 1;
				}
				else{
					high = mid - 1;
				}
			}
			cout << pos + int(pos < n && a[pos + 1] - a[l - 1] - u <= u - a[pos] + a[l - 1]) << " ";
		}
		cout << "\n";
	}
}