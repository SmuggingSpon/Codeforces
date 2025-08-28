#include<bits/stdc++.h>
#define taskname "1919B"
using namespace std;
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
		stack<char>st;
		for(char& c : s){
			if(!st.empty() && st.top() != c){
				st.pop();
			}
			else{
				st.push(c);
			}
		}
		cout << st.size() << "\n";
	}
}