#include<bits/stdc++.h>
#define taskname "2008H"
using namespace std;
const int lim = 1e5 + 1;
int ans[lim], cnt[lim];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, q;
		cin >> n >> q;
		fill(cnt, cnt + n + 1, 0);
		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;
			cnt[x]++;
		}
		for(int i = 1; i <= n; i++){
			cnt[i] += cnt[i - 1];
		}
		for(int x = 1; x <= n; x++){
			int low = 0, high = x - 1;
			while(low <= high){
				int mid = (low + high) >> 1, current = 0;
				for(int i = 0; i <= n; i += x){
					current += cnt[min(i + mid, n)] - (i == 0 ? 0 : cnt[i - 1]);
				}
				if(current > (n >> 1)){
					high = (ans[x] = mid) - 1;
				}
				else{
					low = mid + 1;
				}
			}
		}
		for(int i = 0; i < q; i++){
			int x;
			cin >> x;
			cout << ans[x] << " ";
		}
		cout << "\n";
	}
}