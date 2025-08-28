#include<bits/stdc++.h>
#define taskname "2049E"
using namespace std;
int get(int l, int r){
	cout << "? " << l << " " << r << endl;
	int x;
	cin >> x;
	return x;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		int n;
		cin >> n;
		int f1 = get(1, n >> 2), f2 = get((n >> 2) + 1, n >> 1);
		if(f1 + f2 + get((n >> 1) + 1, (n >> 2) * 3) > 1){
			int low = 1, high = n >> 2;
			while(low < high){
				int mid = (low + high) >> 1, value = (f1 == 1 ? get(1, mid) : get((n >> 2) + 1, (n >> 2) + mid));
				if(value == 1){
					high = mid;
				}				
				else{
					low = mid + 1;
				}
			}
			cout << "! " << high << endl;
		}
		else{
			int low = (n >> 2) + 1, high = n - 1;
			while(low < high){
				int mid = (low + high) >> 1;
				if(mid > (n >> 1)){
					int value = (f1 == 1 || f2 == 1 ? get(1, mid) : get(n - mid + 1, n));
					if(value == 0){
						high = mid;
					}
					else{
						low = mid + 1;
					}
				}
				else{
					int value = (f1 == 0 && f2 == 0 ? get(1, mid) : get((n >> 1) + 1, (n >> 1) + mid));
					if(value == 1){
						high = mid;
					}
					else{
						low = mid + 1;
					}
				}
			}
			cout << "! " << high << endl;
		}
	}
}