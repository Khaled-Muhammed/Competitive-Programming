// link this problem " https://cses.fi/alon/task/1143 "

struct Node {

    int mx;
    Node() : mx(0) {}
    Node(int x) : mx(x) {}
};

struct SegTree {
    int tree_size;
    vector<Node> SegData;
    SegTree(int n) {
        tree_size = 1;
        while (tree_size < n) tree_size <<= 1; // tree_size *= 2
        SegData.assign(2 * tree_size, Node());
    }

    Node merge(const Node & lf, const Node & ri) {
        Node ans = Node();
        ans.mx = max(lf.mx ,ri.mx);
        return ans;
    }

    void build(const vector<int> & arr, int node, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < arr.size())
                SegData[node] = Node(arr[lx]);
            return;
        }

        int mid = (lx + rx) / 2;
        build(arr, 2 * node + 1, lx, mid);
        build(arr, 2 * node + 2, mid, rx);

        SegData[node] = merge(SegData[2 * node + 1], SegData[2 * node + 2]);
    }
    void build(const vector<int> & arr) {
        build(arr, 0, 0, tree_size);
    }

    void set(int idx, int val, int node, int lx, int rx) {
        if(rx - lx == 1) {
            SegData[node].mx = val;
            return;
        }

        int mid = (lx + rx) / 2;
        if(idx < mid)
            set(idx, val, 2 * node + 1, lx, mid);
        else
            set(idx, val, 2 * node + 2, mid, rx);

        SegData[node] = merge(SegData[2 * node + 1], SegData[2 * node + 2]);
    }
    // 0 indexed
    void set(int idx, int val) {
        set(idx, val, 0, 0, tree_size);
    }

    Node get_range(int l, int r, int node, int lx, int rx) {
        if(lx >= r || rx <= l)
            return Node();
        if(lx >= l && rx <= r)
            return SegData[node];

        int mid = (lx + rx) / 2;
        Node lf = get_range(l, r, 2 * node + 1, lx, mid);
        Node ri = get_range(l, r, 2 * node + 2, mid, rx);

        return merge(lf, ri);
    }

    int find_first(int val, int node, int lx, int rx) {
        if (SegData[node].mx < val) return -1;

        if (rx - lx == 1) return lx;

        int mid = (lx + rx) / 2;

        if (SegData[2 * node + 1].mx >= val)
            return find_first(val, 2 * node + 1, lx, mid);
        else
            return find_first(val, 2 * node + 2, mid, rx);
    }
    // r is not inclusive [l, r)
    int get_range(int l, int r) {
        return get_range(l, r, 0, 0, tree_size).mx;
    }
};

void ELLIOT1() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> h(n);
    for (int i = 0; i < n; ++i){
        cin >> h[i];
    }

    vector<int> a(m);
    for (int i = 0; i < m; ++i){
        cin >> a[i];
    }

    SegTree st(n);
    st.build(h);

    for (int x : a) {
        int idx = st.find_first(x, 0, 0, st.tree_size);

        if (idx == -1) {
            cout << 0 << " ";
        } else {
            cout << idx + 1 << " ";
            h[idx] -= x;
            st.set(idx, h[idx]);
        }
    }

    cout << el;
}
