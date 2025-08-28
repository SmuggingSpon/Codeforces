#include<bits/stdc++.h>
#define taskname "2094G"
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
		int q;
		cin >> q;
		ll pref = 0, suf = 0, sum = 0;
		deque<int>d1, d2;
		for(int i = 0; i < q; i++){
			int type;
			cin >> type;
			if(type == 1){
				pref = pref + sum - 1LL * d1.size() * d1.back();
				d1.push_front(d1.back());
				d1.pop_back();
				suf = suf - sum + 1LL * d2.size() * d2.front();
				d2.push_back(d2.front());
				d2.pop_front();
			}
			else if(type == 2){
				swap(d1, d2);
				swap(pref, suf);
			}
			else{
				int k;
				cin >> k;
				d1.push_back(k);
				pref += 1LL * d1.size() * k;
				d2.push_front(k);
				suf += (sum += k);
			}
			cout << pref << "\n";
		}
	}
}