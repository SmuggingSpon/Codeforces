#include<bits/stdc++.h>
#define taskname "2090C"
using namespace std;
pair<int, int>table_id(int x, int y){
    return make_pair(x - int(x % 3 == 2), y - int(y % 3 == 2));
}
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
        vector<set<pair<int, int>>>pos, table;               
        auto work = [&] (int x, int y, int d){
            while(pos.size() <= d){
                pos.emplace_back(set<pair<int, int>>());
                table.emplace_back(set<pair<int, int>>());
            }
            pos[d].emplace(x, y);
            if(x % 3 == 1 && y % 3 == 1){
                table[d].emplace(x, y);
            }
        };
        for(int i = (int(sqrt(n)) << 1) + 10, x = 1; i > 0; i--, x += 3){
            for(int j = 0, y = 1; j < i; y += 3, j++){
                work(x, y, x + y);
                work(x, y + 1, x + y + 1);
                work(x + 1, y, x + y + 1);
                work(x + 1, y + 1, x + y + 4);
            }
        }
        map<pair<int, int>, int>cnt;
        map<pair<int, int>, bool>vis;
        for(int _i = 0, start_0 = 0, start_1 = 0; _i < n; _i++){
            int type;
            cin >> type;
            if(type == 0){
                vector<pair<pair<int, int>, int>>trash;
                for(int i = start_0; i < table.size(); i++){
                    for(auto& it : table[i]){
                        if(cnt[it] == 0){
                            cnt[it] = 1;
                            vis[it] = true;
                            i = table.size();
                            cout << it.first << " " << it.second << "\n";
                            break;
                        }
                        trash.emplace_back(it, i);
                    }
                }
                for(auto& [it, i] : trash){
                    table[i].erase(it);
                }
                while(table[start_0].empty()){
                    start_0++;
                }
            }
            else{
                vector<pair<pair<int, int>, int>>trash;
                for(int i = start_1; i < pos.size(); i++){
                    for(auto& it : pos[i]){
                        if(!vis[it]){
                            vis[it] = true;
                            cnt[table_id(it.first, it.second)]++;
                            cout << it.first << " " << it.second << "\n";
                            i = pos.size();
                            break;
                        }
                        trash.emplace_back(it, i);
                    }
                }
                for(auto& [it, i] : trash){
                    pos[i].erase(it);
                }
                while(pos[start_1].empty()){
                    start_1++;
                }
            }
        }
    }
}