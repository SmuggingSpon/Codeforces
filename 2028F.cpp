#include<bits/stdc++.h>
#define taskname "2028F"
using namespace std;
const int LIM = 1e4 + 1;
bitset<LIM>pref, cur, range_cur, near;
deque<pair<int, bitset<LIM>>>d;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n, m;
		cin >> n >> m;
		pref.reset();
		cur.reset();
		range_cur.reset();
		near.reset();
		pref.set(0);
		cur.set(0);
		range_cur.set(0);
		d.clear();
		for(int _i = 0; _i < n; _i++, pref |= cur){
			int x;
			cin >> x;
			if(x == 0){
				range_cur = cur = near = pref;
				d.clear();
			}
			else if(x == 1){
				cur |= cur << 1;
				range_cur |= cur;
			}
			else{
				d.emplace_back(x, range_cur);
				if(d.size() == 14){
					d.pop_front();
				}
				cur = near;
				for(int i = int(d.size()) - 1, value = 1; i > -1; i--){
					if((value *= d[i].first) >= LIM){
						break;
					}
					cur |= d[i].second << value;
				}
				range_cur = cur;
			}
		}
		cout << (cur.test(m) ? "YES\n" : "NO\n");
	}
}