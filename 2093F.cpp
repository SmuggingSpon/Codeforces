#include<bits/stdc++.h>
#define taskname "2093F"
using namespace std;
template<class T>void maximize(T& a, T b){
    if(a < b){
        a = b;
    }
}
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
        vector<bool>flag(n, false);
        vector<string>a(n);
        for(string& x : a){
            cin >> x;
        }
        vector<vector<string>>b(m, vector<string>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> b[i][j];
                if(a[j] == b[i][j]){
                    flag[j] = true;
                }
            }
        }
        if(find(flag.begin(), flag.end(), false) != flag.end()){
            cout << "-1\n";
            continue;
        }
        int max_cnt = 0;
        for(int i = 0; i < m; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(b[i][j] == a[j]){
                    cnt++;
                }
            }
            maximize(max_cnt, cnt);
        }
        cout << n + ((n - max_cnt) << 1) << "\n";
    }
}