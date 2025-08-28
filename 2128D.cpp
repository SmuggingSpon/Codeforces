#include<bits/stdc++.h>
#define taskname "2128D"
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
		vector<int>a(n);
		for(int& x : a){
			cin >> x;
		}
		stack<int>st;
		ll ans = 0;
		for(int i = n - 1; i > -1; st.push(i--)){
			while(!st.empty() && a[st.top()] < a[i]){
				st.pop();
			}
			ans += 1LL * ((st.empty() ? n : st.top()) - i) * (i + 1);
		}
		cout << ans << "\n";
	}
}