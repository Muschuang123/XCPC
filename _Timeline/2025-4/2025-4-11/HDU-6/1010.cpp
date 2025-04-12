#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 2e5 + 5;
vector<int> g[maxn];
int sz[maxn];
int father[maxn];

void dfs(int x, int fa) {
    sz[x] = 1;
    father[x] = fa;
    for (auto &v : g[x]) {
        if (v == fa) {
            continue;
        }
        dfs(v, x);
        sz[x] += sz[v];
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        sz[i] = 0;
        father[i] = 0;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);
    for (int x = 1; x <= n; x++) {
        vector<i64> a;
        for (auto &v : g[x]) {
            if (v != father[x]) {
                a.push_back(sz[v]);
            }
        }
        if (x != 1) {
            a.push_back(n - sz[x]);
        }

        i64 ans = 0;
        int k = a.size();
        vector<i64> pre = a;

        // 计算 f(i, i)
        i64 fii = n;
        for (int i = 1; i < k; i++) {
            fii += pre[i - 1] * a[i];
            pre[i] += pre[i - 1];
        }
        ans += fii;
        for (int i = 0; i < k; i++) {
            ans += (fii - (n - a[i]) * a[i]) * a[i];
        }

        cout << ans << ' ';
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