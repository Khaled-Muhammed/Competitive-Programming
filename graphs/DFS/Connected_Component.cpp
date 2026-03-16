
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 2e5 + 5;

int n, m, u, v;

vector<int> adj[N];
bool vis[N];

void DFS(int u){
    vis[u] = 1;
    for(auto &v : adj[u]){
        if(!vis[v]){
            DFS(v);
        }
    }
}
int main() {
    
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int connectedComponent = 0;
    for(int i = 0; i < n; ++i){
        if(!vis[i]){
            connectedComponent++;
            DFS(i);
        }
    }
    
    cout << connectedComponent;
}

/*
Samples:
7 6
0 1
1 2
2 5
2 3
2 6
3 4
*/
