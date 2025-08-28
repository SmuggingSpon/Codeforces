#include<bits/stdc++.h>
#define taskname "2104D"
using namespace std;
typedef long long ll;
const int LIM = 1e7 + 5;
vector<int>prime(1, 2);
bitset<LIM>cnt;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	cnt.set();
	for(int i = 3; i * i < LIM; i += 2){
		if(cnt.test(i)){
			for(int j = i * i; j < LIM; j += i << 1){
				cnt.reset(j);
			}
		}
	}
	for(int i = 3; i < LIM; i += 2){
		if(cnt.test(i)){
			prime.emplace_back(i);
		}
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
		sort(a.begin(), a.end(), greater<int>());
		ll sum = accumulate(a.begin(), a.end(), 0LL);
		for(int i = 0; i < n; i++){
			sum -= prime[i];
		}
		while(sum < 0){
			sum -= a.back() - prime[int(a.size()) - 1];
			a.pop_back();
		}
		cout << n - int(a.size()) << "\n";
	}
}