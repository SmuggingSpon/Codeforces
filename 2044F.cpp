#include<bits/stdc++.h>
#define taskname "2044F"
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int n, m, q;
	cin >> n >> m >> q;
	vector<int>a(n), b(m);
	ll A = 0, B = 0;
	for(int& x : a){
		cin >> x;
		A += x;
	}
	for(int& x : b){
		cin >> x;
		B += x;
	}
	vector<ll>have_a, have_b;
	for(int& x : a){
		have_a.emplace_back(A - x);
	}
	for(int& x : b){
		have_b.emplace_back(B - x);
	}
	sort(have_a.begin(), have_a.end());
	sort(have_b.begin(), have_b.end());
	auto work = [&] (ll ia, ll ib){
		return binary_search(have_a.begin(), have_a.end(), ia) && binary_search(have_b.begin(), have_b.end(), ib);
	};
	for(int _q = 0; _q < q; _q++){
		int x;
		cin >> x;
		bool ans = false;
		for(int i = 1; i * i <= abs(x); i++){
			if(x % i == 0){
				int j = x / i;
				if(work(i, j) || work(j, i) || work(-i, -j) || work(-j, -i)){
					ans = true;
					break;
				}
			}
		}
		cout << (ans ? "YES\n" : "NO\n");
	}
}