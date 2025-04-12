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