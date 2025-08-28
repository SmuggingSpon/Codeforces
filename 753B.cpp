#include<bits/stdc++.h>
#define taskname "753B"
using namespace std;
template<class T>bool maximize(T& a, T b){
	if(a < b){
		a = b;
		return true;
	}
	return false;
}
int ask(const string& s){
	cout << s << endl;
	int a, b;
	cin >> a >> b;
	if(a == 4 && b == 0){
		exit(0);
	}
	return a;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	string s = "0000", ans = "";
	int init = ask(s);
	for(int i = 0; i < 4; i++){
		int cur_max = init;
		char d = '0';
		for(char j = '1'; j <= '9'; j++){
			s[i] = j;
			if(maximize(cur_max, ask(s))){
				d = j;				
			}
			s[i] = '0';
		}
		ans += d;
	}
	ask(ans);
}