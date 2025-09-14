// 倍增 LCA | 在 main() 里面先 init() 一下，多测每次建好图 使用 lcabuild()
const int maxn = 2.5e5 + 5;
int root = 1;
vector<int> g[maxn], h[maxn];
int fa[maxn][__lg(maxn) + 1];
int dep[maxn], lg2[maxn], dfn[maxn], sz[maxn];
int dfnknt;

void init() {
    for (int i = 2; i < maxn; i++) {
        lg2[i] = lg2[i / 2] + 1;
    }
}

void lcadfs(int u, int f) {
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    dfn[u] = ++dfnknt;
    sz[u] = 1;
    for (int i = 1; i <= lg2[dep[u]]; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (auto &v : g[u]) {
        if (v == f) continue;
        lcadfs(v, u);
        sz[u] += sz[v];
    }
}

void lcabuild(int n) {
    dfnknt = 0;
    for (int i = 0; i <= n; i++) {
        dfn[i] = dep[i] = sz[i] = 0;
        for (int j = 0; j <= lg2[n]; j++) {
            fa[i][j] = 0;
        }
    }
    lcadfs(root, 0);
}

int LCA(int x, int y) {
    if (dep[x] < dep[y]) {
        swap(x, y);
    }
    while (dep[x] > dep[y]) {
        x = fa[x][lg2[dep[x] - dep[y]]];
    }
    if (x == y) {
        return x;
    }
    for (int i = lg2[dep[x]]; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i], y = fa[y][i];
        }
    }
    return fa[x][0];
}

// vector<int> h[maxn];
{ // main() / solve()
    auto cmp = [&](const int &a, const int &b) {
        return dfn[a] < dfn[b];
    };

    // k 个虚树，i-th 虚树的关键点存在 b[i] 中
    for (int i = 1; i <= k; i++) {
        auto &vec = b[i];
        sort(vec.begin(), vec.end(), cmp);
        int sz = vec.size();
        for (int j = 1; j < sz; j++) {
            vec.push_back(LCA(vec[j - 1], vec[j]));
        }
        sort(vec.begin(), vec.end(), cmp);
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        // vec[0] 是 root
        for (int j = 1; j < vec.size(); j++) {
            int u = vec[j - 1], v = vec[j];
            int lca = LCA(u, v);
            h[lca].push_back(v);
            h[v].push_back(lca);
        }

        // operation...

        for (int j = 0; j < vec.size(); j++) {
            h[vec[j]].clear();
        }
    }
}