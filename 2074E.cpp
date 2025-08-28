#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int get_random(int l, int r){
    return uniform_int_distribution<int>(l, r)(rng);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _t;
    cin >> _t;
    for(int _ = 0; _ < _t; _++){
        int n;
        cin >> n;
        vector<int>p(n);
        iota(p.begin(), p.end(), 1);
        shuffle(p.begin(), p.end(), rng);
        vector<int>a = {p[0], p[1], p[2]};
        while(true){
            cout << "? " << a[0] << " " << a[1] << " " << a[2] << endl;
            int x;
            cin >> x;
            if(x == 0){
                break;
            }
            a.erase(a.begin() + get_random(0, 2));
            a.emplace_back(x);
        }
        cout << "! " << a[0] << " " << a[1] << " " << a[2] << endl;
    }
}