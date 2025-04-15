#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 2e5 + 5;
vector<int> g[maxn];
vector<set<int>> ed;
vector<set<int>> idx;
int leaf;

void dfs(int x) {
    if (g[x].empty()) {
        leaf = x;
        return;
    }
    for (auto &v : g[x]) {
        if (leaf != 0) {
            ed[leaf].insert(v);
            idx[v].insert(leaf);
            leaf = 0;
        }
        dfs(v);
        ed[leaf].insert(v);
        idx[v].insert(leaf);
    }
}

void solve() {
    i64 n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
    ed.clear();
    ed.resize(n + 1);
    idx.clear();
    idx.resize(n + 1);
    vector<int> fa(n + 1);
    for (int i = 2; i <= n; i++) {
        int v;
        cin >> v;
        fa[i] = v;
        g[v].push_back(i);
    }
    leaf = 0;
    dfs(1);

    i64 res = 0;
    i64 cnt = n;
    vector<i64> a(n + 1);
    for (int i = 2; i <= n; i++) {
        i64 u, x;
        cin >> u >> x;
        w -= x;
        res += 2 * x;
        if (fa[u] == u - 1) {
            cnt--;
        } else {
            a[u - 1] = x;
        }
        for (auto &v : idx[u]) {
            if (ed[v].count(u)) {
                ed[v].erase(u);
                if (ed[v].empty()) {
                    // w -= a[v];
                    // res += 2 * a[v];1
                    cnt--;
                }
            }
        }
        cout << res + cnt * w << " \n"[i == n];
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