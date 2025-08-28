#include<bits/stdc++.h>
#define taskname "2075B"
using namespace std;
typedef long long ll;
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
        int n, k;
        cin >> n >> k;
        vector<int>a(n);
        for(int& x : a){
            cin >> x;
        }
        if(k == 1){
            cout << (n == 2 ? a[0] + a[1] : max(*max_element(a.begin() + 1, prev(a.end())) + max(a[0], a[n - 1]), a[0] + a[n - 1])) << "\n";
            continue; 
        }
        ll ans = 0;
        for(int i = 0; i < n; i++){
            priority_queue<int, vector<int>, greater<int>>pq;
            ll sum = 0;
            int temp = 0;
            for(int j = i + 1; j < n; j++){
                if(pq.size() == k - 2){
                    maximize(ans, sum + a[i] + a[j] + max({i == 0 ? 0 : a[0], j == n - 1 ? 0 : a[n - 1], temp}));
                }
                pq.push(a[j]);
                sum += a[j];
                if(pq.size() > k - 2){
                    int x = pq.top();
                    pq.pop();
                    sum -= x;
                    maximize(temp, x);
                }
            }
        }
        cout << ans << "\n";
    }
}