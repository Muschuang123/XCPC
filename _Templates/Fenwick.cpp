struct fenwick {
    int n;
    vector<i64> t;
    fenwick(int _n) {
        n = _n - 1;
        t.resize(n + 1);
    }
    int lowbit(int x) {
        return x & (-x);
    }
    void add(int index, i64 delta) {
        for (int i = index; i <= n; i += lowbit(i)) {
            t[i] += delta;
        }
    }
    i64 query(int index) {
        i64 ans = 0;
        for (int i = index; i > 0; i -= lowbit(i)) {
            ans += t[i];
        }
        return ans;
    }
    i64 query(int l, int r) {
        return query(r) - query(l - 1);
    }
};