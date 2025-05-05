struct SegTree {
    struct Node {
        int l, r, v, laz;
    } t[maxn * 4];

    int a[maxn];

    inline void pushup(int p) {
        auto &me = t[p];
        auto &lc = t[p << 1];
        auto &rc = t[p << 1 | 1];
        me.v = lc.v + rc.v;
    }

    inline void pushdown(int p) {
        auto &me = t[p];
        auto &lc = t[p << 1];
        auto &rc = t[p << 1 | 1];
        if (me.laz) {
            lc.v += me.laz * (lc.r - lc.l + 1);
            rc.v += me.laz * (rc.r - rc.l + 1);
            lc.laz += me.laz;
            rc.laz += me.laz;
            me.laz = 0;
        }
    }

    void build(int p, int l, int r) {
        auto &me = t[p];
        me.l = l, me.r = r;
        if (l == r) {
            me.v = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        pushup(p);
    }

    void add(int p, int l, int r, int d) {
        auto &me = t[p];
        if (l <= me.l && me.r <= r) {
            me.v += d * (me.r - me.l + 1);
            me.laz += d;
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
        auto &me = t[p];
        if (l <= me.l && me.r <= r) {
            return me.v; // 别忘了改这里
        }
        pushdown(p);
        int mid = me.l + me.r >> 1;
        i64 ans = 0;
        // if (r <= mid) { // left
        // } else if (l <= mid) { // left + right
        // } else { // right
        // }
        if (l <= mid)
            ans += query(p << 1, l, r);
        if (r > mid)
            ans += query(p << 1 | 1, l, r);
        return ans;
    }
} T;