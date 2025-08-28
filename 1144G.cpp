#include<bits/stdc++.h>
#define taskname "1144G"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int n;
	cin >> n;
	vector<int>a(n + 1);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	a[n] = -1;
	vector<bool>ans(n);
	for(int i = 0, increase = -INT_MAX, decrease = INT_MAX; i < n; i++){
		if(a[i] > increase && (a[i] < a[i + 1] || a[i] >= decrease)){
			ans[i] = false;
			increase = a[i];
		}
		else if(a[i] < decrease){
			ans[i] = true;
			decrease = a[i];
		}
		else{
			return cout << "NO", 0;
		}
	}
	cout << "YES\n";
	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
}