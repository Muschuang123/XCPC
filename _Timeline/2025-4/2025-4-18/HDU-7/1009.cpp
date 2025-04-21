#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

struct dsu {
    int n, cnt;
    vector<int> fa, sz, e;

    // Index 0 is invalid
    dsu(int _n = 0) {
        n = _n - 1;
        cnt = n;
        fa.resize(n + 1);
        e.resize(n + 1);
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        sz.resize(n + 1, 1);
    }

    int fin(int x) {
        if (fa[x] == x)
            return x;
        return fa[x] = fin(fa[x]);
    }

    bool merg(int u, int v) {
        u = fin(u), v = fin(v);
        if (u == v)
            return 0;
        if (sz[u] < sz[v])
            swap(u, v);
        fa[v] = u;
        sz[u] += sz[v];
        e[u] += e[v] + 1;
        cnt--;
        return 1;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    struct edge {
        int u, v, w;
    };

    vector<edge> a(m + 1);
    for (int i = 1; i <= m; i++) {
        auto &[u, v, w] = a[i];
        cin >> u >> v >> w;
    }
    sort(a.begin() + 1, a.end(), [](const edge &a, const edge &b) {
        return a.w > b.w;
    });

    i64 ans = 0;
    dsu d(n + 1);
    for (int i = 1; i <= m; i++) {
        auto [u, v, w] = a[i];
        int fu = d.fin(u), fv = d.fin(v);
        if (fu == fv) {
            if (d.e[fu] < d.sz[fu]) {
                d.e[fu]++;
                ans += w;
            }
        } else {
            if (d.e[fu] < d.sz[fu] || d.e[fv] < d.sz[fv]) {
                ans += w;
                d.merg(u, v);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}