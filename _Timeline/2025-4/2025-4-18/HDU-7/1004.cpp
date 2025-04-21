#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 5e5 + 5;

struct SegTree {
    struct Node {
        int l, r, l0, r0, l1, r1, mx0, mx1, laz;
    } t[maxn * 4];

    string s;
    int n;

    // p 节点代表的区间翻转
    inline void rev(int p) {
        auto &me = t[p];
        swap(me.l0, me.l1);
        swap(me.r0, me.r1);
        swap(me.mx0, me.mx1);
        me.laz = !me.laz;
    }

    inline void pushup(int p) {
        auto &me = t[p];
        auto &lc = t[p << 1];
        auto &rc = t[p << 1 | 1];
        me.mx0 = max({lc.mx0, rc.mx0, lc.r0 + rc.l0});
        me.mx1 = max({lc.mx1, rc.mx1, lc.r1 + rc.l1});
        me.l0 = lc.l0 == lc.r - lc.l + 1 ? lc.l0 + rc.l0 : lc.l0;
        me.l1 = lc.l1 == lc.r - lc.l + 1 ? lc.l1 + rc.l1 : lc.l1;
        me.r0 = rc.r0 == rc.r - rc.l + 1 ? rc.r0 + lc.r0 : rc.r0;
        me.r1 = rc.r1 == rc.r - rc.l + 1 ? rc.r1 + lc.r1 : rc.r1;
    }

    inline void pushdown(int p) {
        if (t[p].laz) {
            rev(p << 1);
            rev(p << 1 | 1);
            t[p].laz = 0;
        }
    }

    void build(int p, int l, int r) {
        auto &me = t[p];
        me.l = l, me.r = r;
        me.laz = 0;
        if (l == r) {
            if (s[l] == '0') {
                me.l0 = me.r0 = me.mx0 = 1;
                me.l1 = me.r1 = me.mx1 = 0;
            } else {
                me.l1 = me.r1 = me.mx1 = 1;
                me.l0 = me.r0 = me.mx0 = 0;
            }
            me.laz = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        pushup(p);
    }

    void init() {
        n = s.size();
        s = " " + s;
        build(1, 1, n);
    }

    void change(int p, int l, int r) {
        auto &me = t[p];
        if (l <= me.l && me.r <= r) {
            rev(p);
            return;
        }
        pushdown(p);
        int mid = (me.l + me.r) >> 1;
        if (l <= mid)
            change(p << 1, l, r);
        if (r > mid)
            change(p << 1 | 1, l, r);
        pushup(p);
    }

    int query(int p, int l, int r, int k, int op) {
        auto &me = t[p];
        if ((op ? me.mx1 : me.mx0) < k) {
            return -1;
        }
        if (me.l == me.r) {
            return me.l;
        }
        pushdown(p);
        auto &lc = t[p << 1];
        auto &rc = t[p << 1 | 1];
        if ((op ? lc.mx1 : lc.mx0) >= k) {
            // 子段靠左
            return query(p << 1, l, r, k, op);
        } else if ((op ? lc.r1 + rc.l1 : lc.r0 + rc.l0) >= k) {
            // 子段居中
            return lc.r - (op ? lc.r1 : lc.r0) + 1;
        } else {
            // 子段靠右
            return query(p << 1 | 1, l, r, k, op);
        }
        // 左中右顺序不能变
    }
} T;

void solve() {
    cin >> T.s;
    T.init();
    int Q;
    cin >> Q;
    while (Q--) {
        int op, k;
        cin >> op >> k;
        int p = T.query(1, 1, T.n, k, op);
        cout << p << '\n';
        if (p != -1) {
            T.change(1, p, p + k - 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}