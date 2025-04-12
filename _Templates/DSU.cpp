struct dsu {
    int n, cnt;
    vector<int> fa, sz;

    // Index 0 is invalid
    dsu(int _n = 0) {
        n = _n - 1;
        cnt = n;
        fa.resize(n + 1);
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        sz.resize(n + 1, 1);
    }

    int fin(int x) {
        if (fa[x] == x)
            return x;
        return fa[x] = fin(fa[x]);
    }

    bool merg(int u, int v) {
        u = fin(u), v = fin(v);
        if (u == v)
            return 0;
        if (sz[u] < sz[v])
            swap(u, v);
        fa[v] = u;
        sz[u] += sz[v];
        cnt--;
        return 1;
    }
};
