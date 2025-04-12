struct SegTree {
    struct Node {
        int l, r, v, laz;
    } t[maxn * 4];

    int a[maxn];

    inline void pushup(int p) {
        t[p].v = t[p << 1].v + t[p << 1 | 1].v;
    }

    inline void pushdown(int p) {
        if (t[p].laz) {
            t[p << 1].v += t[p].laz * (t[p << 1].r - t[p << 1].l + 1);
            t[p << 1 | 1].v += t[p].laz * (t[p << 1 | 1].r - t[p << 1 | 1].l + 1);
            t[p << 1].laz += t[p].laz;
            t[p << 1 | 1].laz += t[p].laz;
            t[p].laz = 0;
        }
    }

    void build(int p, int l, int r) {
        t[p].l = l, t[p].r = r;
        if (l == r) {
            t[p].v = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        pushup(p);
    }

    void add(int p, int l, int r, int d) {
        if (l <= t[p].l && t[p].r <= r) {
            t[p].v += d * (t[p].r - t[p].l + 1);
            t[p].laz += d;
            return;
        }
        pushdown(p);
        int mid = t[p].l + t[p].r >> 1;
        if (l <= mid)
            add(p << 1, l, r, d);
        if (r > mid)
            add(p << 1 | 1, l, r, d);
        pushup(p);
    }

    i64 query(int p, int l, int r) {
        if (l <= t[p].l && t[p].r <= r) {
            return t[p].v;
        }
        pushdown(p);
        int mid = t[p].l + t[p].r >> 1;
        i64 ans = 0;
        if (l <= mid)
            ans += query(p << 1, l, r);
        if (r > mid)
            ans += query(p << 1 | 1, l, r);
        return ans;
    }
} T;