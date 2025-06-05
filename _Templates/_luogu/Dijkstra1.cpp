#include <bits/stdc++.h>
using namespace std;

struct edge {
    int v, w;
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, s;
    cin >> n >> m >> s;
    vector<edge> g[10004];
    vector<int> d(n + 1), out(n + 1);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    // 把 0 位置也赋值成最大是方便后面 移除 路径最近的点
    for (int i = 0; i <= n; i++)
        d[i] = 0x7fffffff;
    d[s] = 0;
    // 除了自己以外的其他点都要找，n - 1 次循环
    for (int i = 1; i < n; i++) {
        int u = 0;
        for (int j = 1; j <= n; j++)
            // 把 0 位置赋值成最大的原因
            if (!out[j] && d[j] < d[u])
                u = j;
        // 打标记 移出
        out[u] = 1;
        for (auto &c : g[u]) {
            // 取出边的目标点 和 权重
            int v = c.v, w = c.w;
            // 更新最短路
            d[v] = min(d[v], d[u] + w);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << d[i] << ' ';
    }

    return 0;
}