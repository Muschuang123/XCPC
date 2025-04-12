#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 5e5 + 5;

struct edge {
    int v, w;
};

int n;
vector<edge> g[maxn];
i64 d[maxn];
i64 dis = 0;

void dfs(int x, int fa) {
    d[x] = dis;
    for (auto &e : g[x]) {
        if (e.v == fa)
            continue;
        dis += e.w;
        dfs(e.v, x);
        dis -= e.w;
    }
}

void solve() {
    cin >> n;
    dis = 0;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        d[i] = 0;
    }
    for (int i = 1; i <= n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, 0);

    i64 c1 = 0, c2 = 0;
    for (int i = 1; i <= n; i++) {
        c1 += d[i] % 2 == 1;
        c2 += d[i] % 2 == 0;
    }
    cout << c1 * c1 * c1 + c2 * c2 * c2 << '\n';
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