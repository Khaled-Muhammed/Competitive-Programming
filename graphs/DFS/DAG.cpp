

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 2e5 + 5;

const int NOT_VISITED = 0, IN_PROGRESS = 1, VISITED = 2;

int n, m, u, v;

vector<int> adj[N];
int vis[N];

bool DFS(int u) {
    vis[u] = IN_PROGRESS;
    for (int v : adj[u]) {
        if (vis[v] == NOT_VISITED) {
            if (DFS(v))  return true;
        }
        if (vis[v] == IN_PROGRESS) {
            return true;
        }
    }
    vis[u] = VISITED;
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int u = 0; u < n; u++) {
        if (vis[u] == NOT_VISITED) {
            if (DFS(u)) {
                cout << "Cyclic";
                return 0;
            }
        }
    }
    cout << "Acyclic";
    return 0;
}
/*
    Samples:
    6 7
    5 0
    0 4
    0 1
    1 2
    2 4
    2 0
    2 3
*/
