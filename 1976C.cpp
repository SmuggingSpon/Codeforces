#include<bits/stdc++.h>
#define taskname "1976C"
using namespace std;
typedef long long ll;
const int lim = 2e5 + 5;
int a[lim], b[lim], cnt_a[lim], cnt_b[lim];
ll sum_a[lim], sum_b[lim], sa[lim], sb[lim];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = cnt_a[0] = cnt_b[0] = sum_a[0] = sum_b[0] = sa[0] = sb[0] = 0; _ < _t; _++){
		int n, m;
		cin >> n >> m;
		for(int i = 1; i <= n + m + 1; i++){
			cin >> a[i];
			cnt_a[i] = cnt_b[i] = sum_a[i] = sum_b[i] = 0;
		}
		for(int i = 1; i <= n + m + 1; i++){
			cin >> b[i];
			if(a[i] > b[i]){
				cnt_a[i]++;
				sum_a[i] = a[i];
			}
			else{
				cnt_b[i]++;
				sum_b[i] = b[i];
			}
			sa[i] = sa[i - 1] + a[i];
			sb[i] = sb[i - 1] + b[i];
		}
		for(int i = 1; i <= n + m + 1; i++){
			cnt_a[i] += cnt_a[i - 1];
			cnt_b[i] += cnt_b[i - 1];
			sum_a[i] += sum_a[i - 1];
			sum_b[i] += sum_b[i - 1];
		}
		for(int i = 1; i <= n + m + 1; i++){
			int low = 0, high = n + m + 1, p;
			bool a_larger = (a[i] > b[i]);
			while(low <= high){
				int mid = (low + high) >> 1;
				if(cnt_a[mid] - int(mid >= i && a_larger) >= n || cnt_b[mid] - int(mid >= i && !a_larger) >= m){
					high = (p = mid) - 1;
				}
				else{
					low = mid + 1;
				}
			}
			if(p < i){
				if(cnt_a[p] == n){
					cout << sum_a[p] + sum_b[p] + sb[n + m + 1] - sb[p] - b[i] << " ";
				}
				else{
					cout << sum_a[p] + sum_b[p] + sa[n + m + 1] - sa[p] - a[i] << " ";
				}
			}
			else{
				if(cnt_a[p] - int(a_larger) == n){
					cout << sum_a[p] + sum_b[p] - (a[i] > b[i] ? a[i] : b[i]) + sb[n + m + 1] - sb[p] << " ";
				}
				else{
					cout << sum_b[p] + sum_a[p] - (a[i] > b[i] ? a[i] : b[i]) + sa[n + m + 1] - sa[p] << " ";
				}
			}
		}
		cout << "\n";
	}
}