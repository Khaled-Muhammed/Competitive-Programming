struct DSU{
    int cnt, mx_size;
    vector<int> parent, sizes, mn, mx;
 
    void init(int n){
        cnt = n;
 
        mx_size = 1;
        parent.resize(n + 1);
        sizes.resize(n, 1);
 
        for(int i = 1; i <= n; ++i){
            parent[i] = i;
        }
    }
 
    int find_root(int u){
        if(parent[u] == u){
            return u;
        }
        return parent[u] = find_root(parent[u]);
    }
 
    int merge(int u, int v){
        int root_u = find_root(u), root_v = find_root(v);
        if(root_u == root_v) return 0;
 
        if(sizes[root_u] > sizes[root_v]){
            swap(root_u, root_v);
        }
        parent[root_u] = root_v;
        sizes[root_v] += sizes[root_u];
 
        //mx_size = max(mx_size, sizes[root_v]);
 
        cnt--; // count connected component;
        return 1;
    }
 
    bool can_merge(int u, int v){
        return find_root(u) != find_root(v);
    }
};
 
void ELLIOT1() {
 
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    dsu.init(n);
 
    while(m--){
        int u, v;
        string s;
        cin >> s >> u >> v;
        if(s == "union"){
            dsu.merge(u, v);
        }
        else{
            if(dsu.find_root(u) == dsu.find_root(v)){
                cout << "YES" << el;
            }
            else{
                cout << "NO" << el;
            }
        }
    }
}

/*
input
4 4
union 1 2
union 1 3
get 1 4
get 2 3

output
NO
YES
*/
