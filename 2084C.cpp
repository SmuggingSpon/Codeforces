#include<bits/stdc++.h>
#define taskname "2084C"
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int>a(n), b(n);
    for(int& x : a){
        cin >> x;
    }
    for(int& x : b){
        cin >> x;
    }
    map<pair<int, int>, int>pos;
    vector<pair<int, int>>match;
    int alone = -1;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            if(pos[make_pair(b[i], a[i])] != 0){
                match.emplace_back(a[i], b[i]);
            }
        }
        else{
            if((~n & 1) || alone != -1){
                return void(cout << "-1\n");
            }
            alone = i + 1;
        }
        pos[make_pair(a[i], b[i])] = i + 1;
    }
    if(match.size() != (n >> 1)){
        return void(cout << "-1\n");
    }
    vector<pair<int, int>>ans;
    auto work = [&] (int i, int j){
        if(i == j){
            return;
        }
        ans.emplace_back(i, j);
        pos[make_pair(a[i - 1], b[i - 1])] = j;
        pos[make_pair(a[j - 1], b[j - 1])] = i;
        swap(a[i - 1], a[j - 1]);
        swap(b[i - 1], b[j - 1]);
    };
    if(n & 1){
        work(alone, n >> 1);
    }
    int index = 1;
    for(auto& [u, v] : match){
        work(pos[make_pair(v, u)], n - index + 1);
        work(pos[make_pair(u, v)], index++);
    }
    cout << ans.size() << "\n";
    for(auto& [u, v] : ans){
        cout << u << " " << v << "\n";
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
        solve();
    }
}