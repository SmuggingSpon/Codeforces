#include<bits/stdc++.h>
#define taskname "2090D"
using namespace std;
typedef long long ll;
const int lim = 1e5 + 1000;
template<class T>bool maximize(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}
int n, optimal;
vector<int>best;
bitset<lim>cnt;
void work(int p){
    int l = p - 1, r = p + 1;
    bool parity = false;
    vector<int>ans(1, p);
    while(l > 0 && r <= n){
        if(parity){
            ans.emplace_back(l--);
        }
        else{
            ans.emplace_back(r++);
        }
        parity = !parity;
    }
    while(l > 0){
        ans.emplace_back(l--);
    }
    while(r <= n){
        ans.emplace_back(r++);
    }
    int c = 0;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        if(cnt.test(((sum += ans[i]) - 1) / (i + 1) + 1)){
            c++;
        }
    }
    if(maximize(optimal, c)){
        best = ans;
    }
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
    int _t;
    cin >> _t;
    cnt.set();
    for(int i = 4; i < lim; i += 2){
        cnt.reset(i);
    }
    for(int i = 3; i * i < lim; i++){
        if(cnt.test(i)){
            for(int j = i * i; j < lim; j += i << 1){
                cnt.reset(j);
            }
        }
    }
    cnt.reset(0);
    cnt.reset(1);
    for(int _ = 0; _ < _t; _++){
        cin >> n;
        optimal = 0;
        for(int i = -100; i < 100; i++){
            if((n >> 1) + i > 0 && (n >> 1) + i <= n && cnt.test((n >> 1) + i)){
                work((n >> 1) + i);
            }
        }
        for(int& x : best){
            cout << x << " ";
        }
        cout << "\n";
    }
}