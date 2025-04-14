// 链式前向星存图
// https://www.luogu.com.cn/problem/B3643
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 注意边数要开两倍，存无向图
const int maxn = 2e5 + 5;

struct edge {
    int ne, to;
    // int w; (边权)
} g[maxn];

int head[maxn];

int eknt = 0;
void adde(int u, int v/*, int w*/) {
    eknt++;
    g[eknt].to = v;
    g[eknt].ne = head[u];
    // g[eknt].w = w;
    head[u] = eknt;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));

    while (m--) {
        int u, v;
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
        adde(u, v);
        adde(v, u);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " \n"[j == n];
        }
    }

    for (int v = 1; v <= n; v++) {
        vector<int> res;
        for (int i = head[v]; i; i = g[i].ne) {
            res.push_back(g[i].to);
        }
        cout << res.size() << ' ';
        sort(res.begin(), res.end());
        for (auto &e : res) {
            cout << e << ' ';
        }
        cout << '\n';
    }

    return 0;
}