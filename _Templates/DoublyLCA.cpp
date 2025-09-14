// 倍增 LCA | 在 main() 里面先 init() 一下，多测每次建好图 使用 lcabuild()
const int maxn = 2e5 + 5;
int root = 1;
vector<int> g[maxn];
int fa[maxn][__lg(maxn) + 1];
int dep[maxn], lg2[maxn];

void init() {
    for (int i = 2; i < maxn; i++) {
        lg2[i] = lg2[i / 2] + 1;
    }
}

void lcadfs(int u, int f) {
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    for (int i = 1; i <= lg2[dep[u]]; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (auto &v : g[u]) {
        if (v == f) continue;
        lcadfs(v, u);
    }
}

void lcabuild(int n) {
    for (int i = 0; i <= n; i++) {
        dep[i] = 0;
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

int dist(int x, int y) {
    return dep[x] + dep[y] - 2 * dep[LCA(x, y)];
}