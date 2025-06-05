// LCA : 最近公共祖先 Lowest Common Ancestors
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 500005;
int root = 1;
vector<int> g[maxn];
int fa[maxn][__lg(maxn) + 1];
int depth[maxn];
int lg2[maxn];

void init() {
    for (int i = 2; i < maxn; i++) {
        lg2[i] = lg2[i / 2] + 1;
    }
}

void lcadfs(int x, int f) {
    depth[x] = depth[f] + 1;
    fa[x][0] = f;
    for (int i = 1; i <= lg2[depth[x]]; i++) {
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    }
    for (auto &v : g[x]) {
        if (v != f) {
            lcadfs(v, x);
        }
    }
}

void lcabuild(int n) {
    for (int i = 1; i <= n; i++) {
        depth[i] = 0;
        for (int j = 0; j < 25; j++) {
            fa[i][j] = 0;
        }
    }
    lcadfs(root, 0);
}

int LCA(int x, int y) {
    if (depth[x] < depth[y]) {
        swap(x, y);
    }
    while (depth[x] > depth[y]) {
        x = fa[x][lg2[depth[x] - depth[y]]];
    }
    if (x == y) {
        return x;
    }
    for (int i = lg2[depth[x]]; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i], y = fa[y][i];
        }
    }
    return fa[x][0];
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    init();

    int n, q;
    cin >> n >> q >> root;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    lcabuild(n);

    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << '\n';
    }

    return 0;
}