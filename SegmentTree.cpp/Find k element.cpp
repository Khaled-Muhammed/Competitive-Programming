// link a problem -> https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/B
struct Node {

    int sum;
    Node() : sum(0){};
    Node(int x){
       sum = x;
    }

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
        ans.sum = lf.sum + ri.sum;
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
            SegData[node] = Node(val);
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

    // r is not inclusive [l, r)
    int get_range(int l, int r) {
        return get_range(l, r, 0, 0, tree_size).sum;
    }

    int find_k(int k, int node, int lx, int rx) {
        if (rx - lx == 1)
            return lx;

        int mid = (lx + rx) / 2;

        if (SegData[2 * node + 1].sum > k)
            return find_k(k, 2 * node + 1, lx, mid);
        else
            return find_k(k - SegData[2 * node + 1].sum, 2 * node + 2, mid, rx);
    }
    int find_k(int k){
        if (SegData[0].sum <= k) return -1;
        return find_k(k, 0, 0, tree_size);
    }
};

void ELLIOT1() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }

    SegTree st(n);
    st.build(a);

    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int i; cin >> i;
            a[i] = 1 - a[i];
            st.set(i, a[i]);
        } else {
            int k; cin >> k;
            cout << st.find_k(k) << "\n";
        }
    }

