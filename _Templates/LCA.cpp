// 倍增 LCA 先 init() 一下，每次建好图 使用 lcabuild()
const int maxn = 500005;
int root = 1;
vector<int> g[maxn];
int fa[maxn][__lg(maxn) + 1];
int dep[maxn], lg2[maxn];

void init() {
    for (int i = 2; i < maxn; i++) {
        lg2[i] = lg2[i / 2] + 1;
    }
}

void lcadfs(int x, int f) {
    dep[x] = dep[f] + 1;
    fa[x][0] = f;
    for (int i = 1; i <= lg2[dep[x]]; i++) {
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    }
    for (auto &v : g[x]) {
        if (v != f) {
            lcadfs(v, x);
        }
    }
}

void lcabuild(int n) {
    for (int i = 0; i <= n; i++) {
        dep[i] = 0;
        for (int j = 0; j < 25; j++) {
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