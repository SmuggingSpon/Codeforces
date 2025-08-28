#include<bits/stdc++.h>
#define taskname "1977B"
using namespace std;
int a[32];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int x;
		cin >> x;
		memset(a, 0, sizeof(a));
		vector<pair<int, int>>range;
		for(int i = 0; i < 30; i++){
			if(1 << i & x){
				int r = i;
				while(1 << r & x){
					r++;
				}
				range.emplace_back(i, r - 1);
				i = r;
			}
		}
		for(int i = 0; i < range.size(); i++){
			if(range[i].first == range[i].second){
				if(range[i].first == 0 || a[range[i].first - 1] == 0){
					a[range[i].first] = 1;
					continue;
				}
				if(a[range[i].first - 1] == 1){
					a[range[i].first + 1] = 1;
					a[range[i].first - 1] = -1;
					continue;
				}
				a[range[i].first - 1] = 1;
			}
			if(i + 1 < range.size()){
				vector<int>neg(1, range[i].first);
				int last = range[i].second + 1;
				for(int j = i + 1; true; j++){
					if(range[j].first > range[j - 1].second + 2){
						last = range[i = j - 1].second + 1;
						break;
					}
					neg.emplace_back(range[j].first - 1);
					if(j + 1 == range.size()){
						last = range[i = j].second + 1;
						break;
					}
				}
				a[last] = 1;
				for(int& x : neg){
					a[x] = -1;
				}
			}
			else{
				a[range[i].first] = -(a[range[i].second + 1] = 1); 
			}
		}
		cout << "32\n";
		for(int i = 0; i < 32; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
	}
}