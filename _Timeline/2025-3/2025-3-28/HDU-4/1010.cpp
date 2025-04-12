#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int mod = 1e9 + 7;

vector<int> g[100005];
vector<int> h[100005];

void solve() {
    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= c; i++) {
        g[i].clear();
        h[i].clear();
    }
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        // 防止自环连两次
        if (u != v) {
            g[v].push_back(u);
        }
    }

    int lim = sqrtl(m);
    for (int i = 1; i <= c; i++) {
        // 如果 g[i] 连的边数大于块大小
        // 就依靠 其他点连它
        if (g[i].size() > lim) {
            for (auto &v : g[i]) {
                h[v].push_back(i);
            }
        }
    }

    // dat: > lim 的点需要依赖这个，预处理
    // res: 有多少条路径通向这个点
    vector<i64> dat(c + 1), res(c + 1);
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        // cur: 题面中通向 i 这个点的路径
        i64 cur = i == 1;
        if (g[x].size() > lim) {
            // g[x] 连的边数大于块的大小
            // 直接查看 反向图有多少道路径通向它
            cur = (cur + dat[x]) % mod;
        } else {
            // 否则 枚举 进入它的路径并计数
            for (auto &v : g[x]) {
                cur = (cur + res[v]) % mod;
            }
        }
        if (i == n) {
            // 答案就是 第 n 个
            cout << cur << '\n';
            return;
        }
        // 把 第 i 个点的贡献 添加到 a[i] 这个点上
        res[x] = (res[x] + cur) % mod;
        for (auto &v : h[x]) {
            dat[v] = (dat[v] + cur) % mod;
        }
    }

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