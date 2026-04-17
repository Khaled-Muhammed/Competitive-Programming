struct BIT {
    int n;
    vector<int> b;

    BIT(int _n) {
        n = _n;
        b.assign(n +3, 0);
    }

    int get(int idx) {
        int res = 0;
        while (idx > 0) {
            res += b[idx];
            idx -= idx & -idx;
        }
        return res;
    }

    void add(int idx, int v) {
        while (idx <= n) {
            b[idx] += v;
            idx += idx & -idx;
        }
    }

    int get(int l, int r) {
        return get(r) - get(l - 1);
    }

    int get_idx(int idx) {
        return get(idx) - get(idx - 1);
    }

    void set(int idx, int v) {
        int old = get_idx(idx);
        add(idx, -old + v);
    }

    int lower_bound(int sum) {
        if(b[n] < sum)
            return -1;

        int idx = 0;
        for (int step = n; step > 0; step >>= 1) {
            if(b[idx + step] < sum) {
                sum -= b[idx + step];
                idx += step;
            }
        }

        return idx + 1;
    }
};
