const int maxn = 
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

void dfs1(int u, int f) {
    sz[u] = 1;
    dep[u] = dep[f] + 1;
    fa[u] = f;
    for (auto &v : g[u]) {
        if (v == f) {
            continue;
        }
        dfs1(v, u);
        sz[u] += sz[v];
        if (!son[u] || sz[son[u]] < sz[v]) {
            son[u] = v;
        }
    }
}

void dfs2(int u, int t) {
    top[u] = t;
    dfn[u] = ++dfnknt;
    rnk[dfnknt] = u;
    if (!son[u]) {
        return;
    }
    dfs2(son[u], t);
    for (auto &v : g[u]) {
        if (v == son[u] || v == fa[u]) {
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

int jump(int x, int k) {
    if (dep[x] < k)
        return -1;
    int d = dep[x] - k;
    while (dep[top[x]] > d)
        x = fa[top[x]];
    return rnk[dfn[x] - (dep[x] - d)];
}

// SegTree T;

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

i64 queryseg(int x, int y) {
    i64 res = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) {
            swap(x, y);
        }
        res += T.query(1, dfn[top[x]], dfn[x]);
        x = fa[top[x]];
    }
    if (dep[x] < dep[y]) {
        swap(x, y);
    }
    res += T.query(1, dfn[y], dfn[x]);
    return res;
}