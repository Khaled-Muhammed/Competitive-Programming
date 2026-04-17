// 1-indexed

struct MultiSet {
    int n;
    vector<int> b;
    MultiSet (int sz) {
        n = 1;
        while (n < sz) n <<= 1;
        b.assign(n + 1, 0);
    }
    void add(int idx, int val) {
        while (idx <= n) {
            b[idx] += val;
            idx += idx & -idx;
        }
    }
    int get(int idx) {
        int res = 0;
        while (idx > 0) {
            res += b[idx];
            idx -= idx & -idx;
        }
        return res;
    }
    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
    int get_idx(int idx) {
        return get(idx) - get(idx - 1);
    }

    int lower_bound(int sum) {
        int idx = 0;
        for (int step = n; step > 0; step >>= 1) {
            if (b[idx + step] < sum) {
                sum -= b[idx + step];
                idx += step;
            }
        }
        return idx + 1;
    }

    void insert(int val) {
        add(val, 1);
    }
    void insert(int val, int cnt) {
        add(val, cnt);
    }
    void erase(int val) {
        int cnt = get_idx(val);
        if(cnt)
            add(val, -1);
    }
    void erase(int val, int cnt) {
        int mx = get_idx(val);
        cnt = min(cnt, mx);
        add(val, -cnt);
    }

    int operator[](int idx) {
        return lower_bound(idx);
    }

    int size() {
        return b[n];
    }
} MS(1e6);
