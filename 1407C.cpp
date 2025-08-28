#include<bits/stdc++.h>
using namespace std;
int query(int i, int j){
	cout << "? " << i << " " << j << endl;
	int x;
	cin >> x;
	return x;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, i = 1;
	cin >> n;
	vector<int>p(n + 1);
	for(int j = 2; j <= n; j++){
		int ij = query(i, j), ji = query(j, i);
		if(ij > ji){
			p[i] = ij;
			i = j;
		}
		else{
			p[j] = ji;
		}
	}
	p[i] = n;
	cout << "! ";
	for(int i = 1; i <= n; i++){
		cout << p[i] << " ";
	}
	cout << endl;
}