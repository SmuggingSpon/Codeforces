#include<bits/stdc++.h>
#define taskname "2085B"
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
        vector<int>a(n + 1);
        for(int i = a[0] = 1; i <= n; i++){
            cin >> a[i];
        }
        if(find(a.begin(), a.end(), 0) == a.end()){
            cout << "1\n1 " << n << "\n";
        }
        else if(a[1] == 0 && a[n] == 0){
            cout << "3\n1 2\n2 " << n - 1 << "\n1 2\n"; 
        }
        else if(a[n] == 0){
            cout << "2\n2 " << n << "\n1 2\n";
        }
        else{
            cout << "2\n1 " << n - 1 << "\n1 2\n";
        }
    }
}