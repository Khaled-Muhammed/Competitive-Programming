
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 2e5 + 5;

int n, m, u, v;

vector<int> adj[N];
bool vis[N];

void DFS(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v]) {
            DFS(v);
        }
    }
    cout << u << '\n';
}

int main() {
    
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            DFS(i);
        }
    }
    return 0;
}
/*
Samples:
6 8
0 1
0 2
0 5
1 3
3 2
3 4
5 2
5 4
*/
