int n, m;
vector<pair<int, int>> graph[N];
vector<int> dis, par;
void dijkstra(int st){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, st);
    dis[st] = 0;

    while(!pq.empty()){
        int cur = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if(dis[cur] < w){
            continue;
        }
        for(auto &ch : graph[cur]){
            if(dis[ch.first] > w + ch.second){
                dis[ch.first] = w + ch.second;
                pq.emplace(dis[ch.first], ch.first);
                par[ch.first] = cur;
            }
        }
    }
}
void ELLIOT1(){

    cin >> n >> m;

    dis.resize(n + 1);
    par.resize(n + 1);

    for(int i = 0; i < n; ++i){
        dis[i+1] = 1e18, par[i+1] = -1;
    }

    for(int i = 0; i < m; ++i){
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u].emplace_back(v, cost);
        graph[v].emplace_back(u, cost);
    }

    dijkstra(1);

    if(dis[n] == 1e18)
        return void(cout << -1 << endl);

    vector<int> ans;
    int cur = n;
    ans.push_back(cur);
    while (par[cur] != -1)
    {
        ans.push_back(par[cur]);
        cur = par[cur];
    }

    reverse(all(ans));

    for(int x : ans)
        cout << x << ' ';

}

/*
input
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1

output

1 4 3 5 




*/
