#include<bits/stdc++.h>
#define taskname "1922D"
using namespace std;
const int lim = 3e5 + 5;
int n, a[lim], d[lim], nxt[lim], pre[lim];
bitset<lim>vis;
bool check(int index){
	return index > 0 && index <= n && !vis.test(index);
}
int get(int index){
	return check(index) ? a[index] : 0;	
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
	}
	int _t;
	cin >> _t;
	for(int _ = 0; _ < _t; _++){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			pre[i] = i - 1;
			vis.reset(i);
		}
		for(int i = 1; i <= n; i++){
			cin >> d[i];
			nxt[i] = i + 1;
		}
		pre[0] = nxt[n + 1] = 0;
		vector<int>candidate(n);
		iota(candidate.begin(), candidate.end(), 1);
		for(int i = 1; i <= n; i++){
			vector<int>next_candidate;
			sort(candidate.begin(), candidate.end());
			candidate.resize(unique(candidate.begin(), candidate.end()) - candidate.begin());
			int ans = 0;
			stack<int>st;
			for(int& index : candidate){
				if(check(index) && get(pre[index]) + get(nxt[index]) > d[index]){
					ans++;
					st.push(index);
				}
			}
			cout << ans << " ";
			while(!st.empty()){
				int index = st.top();
				st.pop();
				vis.set(index);
				nxt[pre[index]] = nxt[index];
				pre[nxt[index]] = pre[index];
				if(check(pre[index])){
					next_candidate.emplace_back(pre[index]);
				}
				if(check(nxt[index])){
					next_candidate.emplace_back(nxt[index]);
				}
			}
			candidate = next_candidate;
		}
		cout << "\n";
	}
}