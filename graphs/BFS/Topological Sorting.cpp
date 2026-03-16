
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
vector<int> vis, levels, indegree, topo;

void bfs(){
    priority_queue<int, vector<int>, greater<int>> q;

    for(int i = 1; i <= n; ++i){
        if(!indegree[i]){
            q.push(i);
            vis[i] = 1;
            levels[i] = 0;
        }
    }

    while(!q.empty()){
        int cur = q.top();
        q.pop();

        topo.push_back(cur);
        for(auto ch : graph[cur]){
            if(!vis[ch]){
                indegree[ch]--;

                if(!indegree[ch]){
                    q.push(ch);
                    vis[ch] = 1;
                    levels[ch] = levels[cur] + 1;
                }
            }
        }
    }
}
void TheManWhoNeverGivesUp() {

    cin >> n >> m;

    graph.resize(n + 1);
    vis.resize(n + 1);
    levels.resize(n + 1);
    indegree.resize(n + 1);

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
    }

    bfs();

    if(topo.size() < n){
        cout << "Sandro fails.";
        return;
    }
    for(auto it : topo){
        cout << it << " ";
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
input
8 9
1 4
1 2
4 2
4 3
3 2
5 2
3 5
8 2
8 6

output
1 4 3 5 7 8 2 6 
*/
