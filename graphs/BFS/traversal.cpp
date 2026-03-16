#include <bits/stdc++.h>
#define int long long
#define el '\n'
#define all(x) x.begin(), x.end()
#define MOD 1'000'000'007;
using namespace std;
//====================//

void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int dx_all[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy_all[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1000 + 5, M = 2e5 + 5, OO = 0x3f3f3f3f;

int n, m;
vector<vector<int>> graph;
vector<int> vis, levels, traversal;

void bfs(int start){
    queue<int> q;

    q.push(start);
    vis[start] = 1;
    levels[start] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        traversal.push_back(cur);

        for(auto ch : graph[cur]){
            if(!vis[ch]){
                q.push(ch);
                vis[ch] = 1;
                levels[ch] = levels[cur] + 1;
            }
        }
    }
}
void TheManWhoNeverGivesUp() {

    cin >> n >> m;

    graph.resize(n + 1);
    vis.resize(n + 1);
    levels.resize(n + 1);

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs(1);

    for(auto i : traversal){
        cout << i << " ";
    }
}
signed main(){

//    std::freopen("longpath.in", "r", stdin);
//    std::freopen("longpath.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    file();

    int tc = 1;
    //cin >> tc;
    for (int i = 1; i <= tc; ++i) {
        //  cout<<"Case #"<<i<<": ";
        TheManWhoNeverGivesUp();
    }
}

/*
intput
9 8
1 2
1 3
2 4
2 5
3 6
6 9
5 7
5 8

output
1 2 3 4 5 6 7 8 9 
*/
