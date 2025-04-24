#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 只有 左右两侧 一侧是 00 一侧是 11 的段
// 可以在拿走之后把两侧的段合并，少拿一个串，
// 所以先拿这种。
// 我们可以统计 00 和 11 的个数，取 min 就是这种段个数
// 剩下的 ：一侧是 00，另一侧是 00；一侧是 11，另一侧是 11 只能是拿走一个算一个

// 一共需要拿的数量：cnt(00) + cnt(11) + 1
// 因为第一种情况的存在，答案就是 cnt(00) + cnt(11) + 1 - min(cnt(00), cnt(11))
// 即 max(cnt(00), cnt(11)) + 1

const int maxn = 1e6 + 6;

struct SegTree {
    struct Node {
        int l, r, v0, v1;
        bool L, R, laz;
    } t[maxn * 4];

    int a[maxn];

    inline void pushup(int p) {
        auto &me = t[p];
        auto &lc = t[p << 1], rc = t[p << 1 | 1];
        me.v0 = lc.v0 + rc.v0;
        me.v1 = lc.v1 + rc.v1;
        me.v1 += lc.R == rc.L && lc.R == 1;
        me.v0 += lc.R == rc.L && lc.R == 0;
        me.L = lc.L;
        me.R = rc.R;
    }

    inline void pushdown(int p) {
        auto &lc = t[p << 1], &rc = t[p << 1 | 1];
        if (t[p].laz) {
            swap(lc.v0, lc.v1);
            swap(rc.v0, rc.v1);
            lc.L = !lc.L;
            lc.R = !lc.R;
            rc.L = !rc.L;
            rc.R = !rc.R;
            t[p << 1].laz ^= t[p].laz;
            t[p << 1 | 1].laz ^= t[p].laz;
            t[p].laz = 0;
        }
    }

    void build(int p, int l, int r) {
        t[p].l = l, t[p].r = r;
        t[p].L = a[l], t[p].R = a[r];
        t[p].laz = 0;
        t[p].v0 = t[p].v1 = 0;
        if (l == r) {
            return;
        }
        int mid = l + r >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        pushup(p);
    }

    void add(int p, int l, int r) {
        if (l <= t[p].l && t[p].r <= r) {
            swap(t[p].v0, t[p].v1);
            t[p].L = !t[p].L;
            t[p].R = !t[p].R;
            t[p].laz = !t[p].laz;
            return;
        }
        pushdown(p);
        int mid = t[p].l + t[p].r >> 1;
        if (l <= mid)
            add(p << 1, l, r);
        if (r > mid)
            add(p << 1 | 1, l, r);
        pushup(p);
    }

    array<int, 4> query(int p, int l, int r) {
        if (l <= t[p].l && t[p].r <= r) {
            return {t[p].L, t[p].R, t[p].v0, t[p].v1};
        }
        pushdown(p);
        int mid = t[p].l + t[p].r >> 1;
        int L1, R1, L2, R2, v0 = 0, v1 = 0;
        bool ok1 = 0, ok2 = 0;
        if (l <= mid) {
            auto res = query(p << 1, l, r);
            L1 = res[0];
            R1 = res[1];
            v0 += res[2];
            v1 += res[3];
            ok1 = 1;
        }
        if (r > mid) {
            auto res = query(p << 1 | 1, l, r);
            L2 = res[0];
            R2 = res[1];
            v0 += res[2];
            v1 += res[3];
            ok2 = 1;
        }
        if (ok1 && ok2) {
            v0 += R1 == L2 && R1 == 0;
            v1 += R1 == L2 && R1 == 1;
            return {L1, R2, v0, v1};
        } else if (ok1) {
            return {L1, R1, v0, v1};
        } else {
            return {L2, R2, v0, v1};
        }
    }
} T;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, Q;
    cin >> n >> Q;
    for (int i = 1; i <= n; i++) {
        char x;
        cin >> x;
        T.a[i] = (x - '0');
    }
    T.build(1, 1, n);
    while (Q--) {
        char op;
        int l, r;
        cin >> op >> l >> r;
        if (op == 'Q') {
            auto res = T.query(1, l, r);
            cout << max(res[2], res[3]) + 1 << '\n';
        } else {
            T.add(1, l, r);
        }
        cout << "";
    }

    return 0;
}