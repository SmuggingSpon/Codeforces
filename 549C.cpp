#include<bits/stdc++.h>
#define taskname "549C"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int n, k, odd = 0, even = 0;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x & 1){
			odd++;
		}
		else{
			even++;
		}
	}
	if(n == k){
		cout << ((odd & 1) ? "Stannis" : "Daenerys");
	}
	else if((n - k) & 1){
		if(k & 1){
			cout << (odd <= ((n - k) >> 1) ? "Daenerys" : "Stannis");
		}
		else{
			cout << (max(min(odd - 1, even), min(odd, even - 1)) <= ((n - k) >> 1) ? "Daenerys" : "Stannis");
		}
	}
	else{
		if(k & 1){
			cout << (even <= ((n - k + 1) >> 1) ? "Stannis" : "Daenerys");
		}
		else{
			cout << "Daenerys";
		}
	}
}