#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;
using namespace std;

const int maxn = 1e5 + 5;
int mod = 1e9 + 7;
int rt = 1;

// 使用前先 init()
struct DST {
    int tot = 1;
    struct Node {
        int ls, rs, v, laz;
    } t[maxn * 66]; // Q(查询次数) * 2logV(值域大小)
    // 极端情况下单次修改可能创建 接近 2logV 个节点

#define me t[p]
#define lc t[t[p].ls]
#define rc t[t[p].rs]

    void init() {
        for (int i = 0; i <= tot; i++) {
            t[i] = {0, 0, 0, 0};
        }
        tot = 1;
    }
    void pushup(int p) {
        me.v = (lc.v + rc.v) % mod; // pushup
    }
    void pushdown(int p, int L, int R) {
        if (!me.laz) return;
        int M = L + R >> 1;
        if (!me.ls) me.ls = ++tot;
        if (!me.rs) me.rs = ++tot;
        lc.v = (lc.v + 1LL * me.laz * (M - L + 1)) % mod;
        rc.v = (rc.v + 1LL * me.laz * (R - M)) % mod;
        lc.laz = (lc.laz + me.laz) % mod;
        rc.laz = (rc.laz + me.laz) % mod;
        me.laz = 0;
    }
    // int rt = 1;
    // add(rt, 1, n, l, r, d);
    void add(int &p, int L, int R, int l, int r, int d) {
        if (!p) p = ++tot; // 开点
        if (r < L || R < l) return;
        if (l <= L && R <= r) {
            me.v = (1LL * me.v + 1LL * (R - L + 1) * d) % mod;
            me.laz = (me.laz + d) % mod;
            return;
        }
        pushdown(p, L, R);
        int M = L + R >> 1;
        add(me.ls, L, M, l, r, d);
        add(me.rs, M + 1, R, l, r, d);
        pushup(p);
    }
    int query(int p, int L, int R, int l, int r) {
        if (!p) return 0;
        if (l <= L && R <= r) return t[p].v;
        pushdown(p, L, R);
        int res = 0;
        int M = L + R >> 1;
        if (l <= M) res = (res + query(t[p].ls, L, M, l, r)) % mod;
        if (r > M) res = (res + query(t[p].rs, M + 1, R, l, r)) % mod;
        return res;
    }

#undef me
#undef lc
#undef rc

} T;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    T.init();
    int m, n = 1000000000;
    cin >> m >> mod;
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y, z;
            cin >> x >> y >> z;
            T.add(rt, 1, n, x, y, z);
        } else {
            int x, y;
            cin >> x >> y;
            cout << T.query(rt, 1, n, x, y) << '\n';
        }
    }

    return 0;
}