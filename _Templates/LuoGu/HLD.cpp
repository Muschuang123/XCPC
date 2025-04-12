#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int mod;

const int maxn = 1e5 + 5;
vector<int> g[maxn];
int fa[maxn];   // 父亲
int dep[maxn];  // 深度
int sz[maxn];   // 子树节点个数
int son[maxn];  // 重儿子
int top[maxn];  // 重链
int dfn[maxn];  // DFS序
int rnk[maxn];  // DFS序逆
int dfnknt = 0;
int root = 1;

void dfs1(int x, int father) {
    sz[x] = 1;
    dep[x] = dep[father] + 1;
    fa[x] = father;
    for (auto &v : g[x]) {
        if (v == father) {
            continue;
        }
        dfs1(v, x);
        sz[x] += sz[v];
        if (!son[x] || sz[son[x]] < sz[v]) {
            son[x] = v;
        }
    }
}

void dfs2(int x, int t) {
    top[x] = t;
    dfn[x] = ++dfnknt;
    rnk[dfnknt] = x;
    if (!son[x]) {
        return;
    }
    dfs2(son[x], t);
    for (auto &v : g[x]) {
        if (v == son[x] || v == fa[x]) {
            continue;
        }
        dfs2(v, v);
    }
}

void hldbuild(int n) {
    dfnknt = 0;
    for (int i = 0; i <= n; i++) {
        fa[i] = dep[i] = sz[i] = son[i] = top[i] = dfn[i] = rnk[i] = 0;
    }
    dfs1(root, 0);
    dfs2(root, root);
}

int LCA(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) {
            swap(x, y);
        }
        x = fa[top[x]];
    }
    return dep[x] < dep[y] ? x : y;
}

struct SegTree {
    struct Node {
        int l, r, v, laz;
    } t[maxn * 4];

    int a[maxn];

    inline void pushup(int p) {
        t[p].v = t[p << 1].v + t[p << 1 | 1].v;
        t[p].v %= mod;
    }

    inline void pushdown(int p) {
        if (t[p].laz) {
            t[p << 1].v += 1LL * t[p].laz * (t[p << 1].r - t[p << 1].l + 1) % mod;
            t[p << 1 | 1].v += 1LL * t[p].laz * (t[p << 1 | 1].r - t[p << 1 | 1].l + 1) % mod;
            t[p << 1].laz += t[p].laz;
            t[p << 1 | 1].laz += t[p].laz;
            t[p << 1].laz %= mod;
            t[p << 1 | 1].laz %= mod;
            t[p].laz = 0;
        }
    }

    void build(int p, int l, int r) {
        t[p].l = l, t[p].r = r;
        if (l == r) {
            t[p].v = a[l] % mod;
            return;
        }
        int mid = l + r >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        pushup(p);
    }

    void add(int p, int l, int r, int d) {
        if (l <= t[p].l && t[p].r <= r) {
            t[p].v += 1LL * d * (t[p].r - t[p].l + 1) % mod;
            t[p].laz += d;
            t[p].v %= mod;
            t[p].laz %= mod;
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

    int query(int p, int l, int r) {
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
        ans %= mod;
        return ans;
    }
} T;

void addseg(int x, int y, int z) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) {
            swap(x, y);
        }
        T.add(1, dfn[top[x]], dfn[x], z);
        x = fa[top[x]];
    }
    if (dep[x] < dep[y]) {
        swap(x, y);
    }
    T.add(1, dfn[y], dfn[x], z);
}

int queryseg(int x, int y) {
    i64 res = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) {
            swap(x, y);
        }
        res = (res + T.query(1, dfn[top[x]], dfn[x])) % mod;
        x = fa[top[x]];
    }
    if (dep[x] < dep[y]) {
        swap(x, y);
    }
    res = (res + T.query(1, dfn[y], dfn[x])) % mod;
    return res;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m >> root >> mod;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    hldbuild(n);

    for (int i = 1; i <= n; i++) {
        T.a[dfn[i]] = a[i];
    }

    T.build(1, 1, n);

    while (m--) {
        int op, x, y, z;
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> z;
            addseg(x, y, z);
        } else if (op == 2) {
            cin >> x >> y;
            cout << queryseg(x, y) << '\n';
        } else if (op == 3) {
            cin >> x >> z;
            T.add(1, dfn[x], dfn[x] + sz[x] - 1, z);
        } else if (op == 4) {
            cin >> x;
            cout << T.query(1, dfn[x], dfn[x] + sz[x] - 1) % mod << '\n';
        }
    }

    return 0;
}