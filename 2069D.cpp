#include<bits/stdc++.h>
#define taskname "2069D"
using namespace std;
template<class T>void minimize(T& a, T b){
    if(a > b){
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
        string _s;
        cin >> _s;
        int _left = 0, _right = int(_s.size()) - 1;
        while(_left < _right && _s[_left] == _s[_right]){
            _left++;
            _right--;
        }
        if(_left >= _right){
            cout << "0\n";
            continue;
        }
        string s = "";
        for(int i = _left; i <= _right; i++){
            s += _s[i] - 97;
        }
        int n = s.size(), ans = n, middle = (n >> 1) - 1;
        for(int _q = 0; _q < 2; _q++, reverse(s.begin(), s.end())){
            int low = 0, high = ans - 1;
            while(low <= high){
                int mid = (low + high) >> 1;
                bool flag = true;
                vector<int>cnt(26, 0);
                for(int i = 0; i <= mid; i++){
                    cnt[s[i]]++;
                }
                if(mid <= middle){
                    for(int i = 0; i <= mid; i++){
                        if(cnt[s[n - i - 1]]-- == 0){
                            flag = false;
                            break;
                        }
                    }
                    for(int i = mid + 1; i <= middle; i++){
                        if(s[i] != s[n - i - 1]){
                            flag = false;
                            break;
                        }
                    }
                }
                else{
                    for(int i = mid + 1; i < n; i++){
                        if(cnt[s[i]]-- == 0){
                            flag = false;
                            break;
                        }
                    }
                }
                if(flag){
                    ans = mid + 1;
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
        }
        cout << ans << "\n";
    }
}