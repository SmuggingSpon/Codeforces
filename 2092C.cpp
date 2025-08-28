#include<bits/stdc++.h>
#define taskname "2092C"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    int _t;
    cin >> _t;
    for(int _ = 0; _ < _t; _++){
        int n;
        cin >> n;
        bool odd = false, even = false;
        vector<int>a(n), cnt(2, 0);
        for(int& x : a){
            cin >> x;
            cnt[x & 1]++;
        }
        if(cnt[0] == 0 || cnt[1] == 0){
            cout << *max_element(a.begin(), a.end()) << "\n";
            continue;
        }
        cout << accumulate(a.begin(), a.end(), 0LL) - cnt[1] + 1 << "\n";
    }
}