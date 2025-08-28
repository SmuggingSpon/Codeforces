#include<bits/stdc++.h>
using namespace std;
const int lim = 2005;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int get_random(int l, int r){
	return uniform_int_distribution<int>(l, r)(rng);
}
int n, a[lim];
char ask(int index){
	cout << "? " << index << endl;
	char ans;
	cin >> ans;
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		cin >> n;
		int current_x = 1, index = get_random(1, n);
		while(ask(index) != '='){}
		vector<int>L, R;
		for(int i = 1; i <= n; i++){
			if(i != index){
				if(ask(i) == '<'){
					current_x++;
					L.emplace_back(i);
				}
				else{
					R.emplace_back(i);
				}
				ask(index);
			}
		}
		stack<vector<int>>st;
		st.push(L);
		st.push(R);
		a[index] = current_x;
		while(!st.empty()){
			vector<int>p = st.top();
			st.pop();
			if(!p.empty()){
				index = p[get_random(0, int(p.size()) - 1)];
				while(true){
					char current = ask(index);
					if(current == '<'){
						current_x--;
					}
					else if(current == '>'){
						current_x++;
					}
					else{
						break;
					}
				}
				a[index] = current_x;
				L.clear();
				R.clear();
				for(int& i : p){
					if(i != index){
						if(ask(i) == '<'){
							L.emplace_back(i);
						}
						else{
							R.emplace_back(i);
						}
						ask(index);
					}
				}
				if(L.size() < R.size()){
					swap(L, R);
				}
				st.push(L);
				st.push(R);
			}
		}
		cout << "! ";
		for(int i = 1; i <= n; i++){
			cout << a[i] << " ";
		}
		cout << endl;
	}
}