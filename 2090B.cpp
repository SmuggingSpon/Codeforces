#include<bits/stdc++.h>
#define taskname "2090B"
using namespace std;
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
        vector<vector<char>>a(n, vector<char>(m));
        bool ans = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
                if(a[i][j] == '1'){
                    bool flag = true;
                    for(int k = 0; k < i; k++){
                        if(a[k][j] == '0'){
                            flag = false;
                            break;
                        }
                    }
                    if(!flag){
                        for(int k = 0; k < j; k++){
                            if(a[i][k] == '0'){
                                flag = true;
                                break;
                            }
                        }
                        if(flag){
                            ans = false;
                        }
                    }
                }
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}