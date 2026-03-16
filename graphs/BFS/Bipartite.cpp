
int n, m;
vector<vector<int>> graph;
vector<int> color;
bool ok = true;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(auto ch : graph[cur]){
            if(color[ch] == -1){
                color[ch] = 1 - color[cur];
                q.push(ch);
            }
            else{
                if(color[ch] == color[cur]){
                    ok = false;
                }
            }
        }
    }
}
void ELLIOT1() {

    cin >> n >> m;

    graph.assign(n + 1, {});
    color.assign(n + 1, -1);

    ok = true;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i = 1; i <= n; ++i){
        if(color[i] == -1){
            bfs(i);
        }
    }

    if(!ok){
        cout << "Suspicious bugs found!" << endl;
    }
    else{
        cout << "No suspicious bugs found!" << endl;
    }
}
/*
Example
input
2
3 3
1 2
2 3
1 3
4 2
1 2
3 4

output
Bipartite!
Not Bipartite!
*/
