// https://www.cnblogs.com/qzhfx/p/18206957#_label7
// https://codeforces.com/gym/105173/attachments/download/25612/Solution.pdf
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 倍增 LCA 先 init() 一下，每次建好图 使用 lcabuild()
const int maxn = 100005;
int root = 1;
vector<int> g[maxn];
int fa[maxn][__lg(maxn) + 1];
int depth[maxn];
int lg2[maxn];
int in[maxn], out[maxn];
int dfn = 0;
int pre[maxn];

void init() {
    for (int i = 2; i < maxn; i++) {
        lg2[i] = lg2[i / 2] + 1;
    }
}

void lcadfs(int x, int f) {
    in[x] = ++dfn;
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
    out[x] = dfn;
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

int dist(int x, int y) {
    return depth[x] + depth[y] - 2 * depth[LCA(x, y)];
}

// 求 x 的第 z 级祖先
int ances(int x, int z) {
    int dep = depth[x] - z;
    while (depth[x] > dep) {
        x = fa[x][lg2[depth[x] - dep]];
    }
    return x;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    init();
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    lcabuild(n);

    vector<pair<int, int>> a(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i].first >> a[i].second;
    }
    
    auto check = [&](int mid) {
        i64 need = 0;
        for (int i = 1; i <= n + 1; i++) {
            pre[i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            auto [x, y] = a[i];
            int dis = dist(x, y);
            // 如果 dis <= mid
            // 如果跟在 路径外面，那么直接顺路
            // 如果跟在 路径里面，那么更近了，两个人相向而行
            if (dis <= mid) {
                continue;
            } else {
                int lca = LCA(x, y);
                int lenx = dist(x, lca), leny = dist(y, lca);
                need += 2;
                // 考虑如何做才能让 x 在 mid 步内到达首都
                if (lenx > mid) {
                    // 截断点在 x ~ lca 这条链上
                    int an = ances(x, mid);
                    pre[in[an]]++;
                    pre[out[an] + 1]--;
                } else {
                    // 截断点在 lca ~ y 这条链上
                    int an = ances(y, dis - mid - 1);
                    pre[1]++;
                    pre[in[an]]--;
                    pre[out[an] + 1]++;
                    pre[n + 1]--;
                }
                // 对 y 来说同理
                if (leny > mid) {
                    int an = ances(y, mid);
                    pre[in[an]]++;
                    pre[out[an] + 1]--;
                } else {
                    int an = ances(x, dis - mid - 1);
                    pre[1]++;
                    pre[in[an]]--;
                    pre[out[an] + 1]++;
                    pre[n + 1]--;
                }
            }
        }
        int fl = 0;
        for (int i = 1; i <= n; i++) {
            pre[i] += pre[i - 1];
            if (pre[i] == need) {
                fl = 1;
            }
        }
        return fl;
    };

    int l = -1, r = n - 1;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << '\n';

    return 0;
}