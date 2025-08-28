#include<bits/stdc++.h>
#define taskname "2034D"
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
		vector<priority_queue<int>>pq(3);
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			pq[a[i]].push(i);
		}
		vector<pair<int, int>>ans;
		for(int i = 1; i <= n; i++){
			if(a[i] == 2){
				int x = pq[1].top();
				pq[a[i] = 1].pop();
				pq[a[x] = 2].push(x);
				ans.emplace_back(i, x);
			}
			if(a[i] == 1){
				if(pq[0].empty() || pq[0].top() < i){
					for(int j = i + 1; j <= n; j++){
						if(a[j] == 2){
							if(pq[1].empty() || pq[1].top() < j){
								break;
							}
							int x = pq[1].top();
							pq[a[j] = 1].pop();
							a[x] = 2;
							ans.emplace_back(j, x);
						}
					}
					break;
				}
				else{
					int x = pq[0].top();
					pq[a[i] = 0].pop();
					pq[a[x] = 1].push(x);
					ans.emplace_back(i, x);
 				}
			}
		}
		cout << ans.size() << "\n";
		for(auto& [u, v] : ans){
			cout << u << " " << v << "\n";
		}
	}
}