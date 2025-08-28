#include<bits/stdc++.h>
#define taskname "1202C"
using namespace std;
typedef long long ll;
template<class T>void minimize(T& a, T b){
	if(a > b){
		a = b;
	}
}
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
		string s;
		cin >> s;
		vector<int>ws(1, 0), ad(1, 0);
		for(char& c : s){
			ws.emplace_back(ws.back());
			ad.emplace_back(ad.back());
			if(c == 'W'){
				ws.back()--;
			}
			else if(c == 'S'){
				ws.back()++;
			}
			else if(c == 'A'){
				ad.back()--;
			}
			else{
				ad.back()++;
			}
		}
		vector<int>ws_min(ws.size()), ws_max(ws.size()), ad_min(ad.size()), ad_max(ad.size());
		ws_min.back() = ws_max.back() = ws.back();
		ad_min.back() = ad_max.back() = ad.back();
		for(int i = int(ws.size()) - 2; i > -1; i--){
			ws_min[i] = min(ws_min[i + 1], ws[i]);
			ws_max[i] = max(ws_max[i + 1], ws[i]);
			ad_min[i] = min(ad_min[i + 1], ad[i]);
			ad_max[i] = max(ad_max[i + 1], ad[i]);
		}
		ll ans = 1LL * (ws_max[0] - ws_min[0] + 1) * (ad_max[0] - ad_min[0] + 1);
		for(int i = 1, w = 0, s = 0, a = 0, d = 0; i < ws.size(); i++){
			minimize(ans, 1LL * (max({s, ws_max[i] + 1, ws[i - 1] + 1}) - min({w, ws_min[i] + 1, ws[i - 1] + 1}) + 1) * (max(d, ad_max[i]) - min(a, ad_min[i]) + 1));
			minimize(ans, 1LL * (max({s, ws_max[i] - 1, ws[i - 1] - 1}) - min({w, ws_min[i] - 1, ws[i - 1] - 1}) + 1) * (max(d, ad_max[i]) - min(a, ad_min[i]) + 1));
			minimize(ans, 1LL * (max(s, ws_max[i]) - min(w, ws_min[i]) + 1) * (max({d, ad_max[i] + 1, ad[i - 1] + 1}) - min({a, ad_min[i] + 1, ad[i - 1] + 1}) + 1));
			minimize(ans, 1LL * (max(s, ws_max[i]) - min(w, ws_min[i]) + 1) * (max({d, ad_max[i] - 1, ad[i - 1] - 1}) - min({a, ad_min[i] - 1, ad[i - 1] - 1}) + 1));
			minimize(w, ws[i]);
			maximize(s, ws[i]);
			minimize(a, ad[i]);
			maximize(d, ad[i]);
		}
		cout << ans << "\n";
	}
}