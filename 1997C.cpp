#include<bits/stdc++.h>
#define taskname "1997C"
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
		string s;
		cin >> n >> s;
		s = '#' + s;
		int open = 1;
		ll ans = 0;
		stack<int>st;
		st.push(1);
		for(int i = 2; i <= n; i++){
			if(~i & 1){
				if(s[i] == ')'){
					open--;
					ans += i - st.top();
					st.pop();
				}
				else{
					open++;
					st.push(i);
				}
			}
			else{
				if(open > 1 || (open == 1 && s[i + 1] == '(')){
					open--;
					ans += i - st.top();
					st.pop();
				}
				else{
					st.push(i);
					open++;	
				}
			}
		}
		cout << ans << "\n";
	}
}