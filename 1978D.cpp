#include<bits/stdc++.h>
#define taskname "1978D"
using namespace std;
typedef long long ll;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
const int INF = 1e9;
const ll LIM = 3e14;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, c;
		cin >> n >> c;
		vector<int>a(n + 1), suffix_max(n + 2), prefix_max(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		a[1] += c;
		suffix_max[n + 1] = prefix_max[0] = 0;
		for(int i = n; i > 0; i--){
			suffix_max[i] = max(suffix_max[i + 1], a[i]);
		}
		for(int i = 1; i <= n; i++){
			prefix_max[i] = max(prefix_max[i - 1], a[i]);
		}
		ll prefix_sum = 0;
		for(int i = 1; i <= n; prefix_sum += a[i++]){
			if(prefix_sum + a[i] < suffix_max[i + 1]){
				cout << i << " ";
			}
			else if(a[i] < max(prefix_max[i - 1] + 1, suffix_max[i + 1])){
				cout << i - 1 << " ";
			}
			else{
				cout << "0 ";
			}
		}
		cout << "\n";
	}
}