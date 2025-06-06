// https://codeforces.com/gym/105901/problem/E
// 代码功能：把所有奇数度节点补成偶数度，然后取出所有环。
#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;
using namespace std;

const int maxn = 2e5 + 5;
vector<pair<int, int>> g[maxn];
vector<int> vis, mp, lu, del;
vector<pair<int, int>> ed;
int co = 0;

void dfs(int x, int fe) {
    if (vis[x]) {
        vis[ed[fe].first] = vis[ed[fe].second] = 0;
        del[fe] = 1;
        mp[fe] = ++co;
        while (ed[lu.back()].first != x && ed[lu.back()].second != x) {
            int e = lu.back();
            auto [u, v] = ed[e];
            vis[u] = vis[v] = 0;
            lu.pop_back();
            mp[e] = co;
        }
        vis[ed[lu.back()].first] = vis[ed[lu.back()].second] = 0;
        mp[lu.back()] = co;
        lu.pop_back();
    } else {
        lu.push_back(fe);
    }
    vis[x] = 1;
    while (g[x].size()) {
        auto [v, id] = g[x].back();
        g[x].pop_back();
        if (id == fe || del[id]) {
            continue;
        }
        del[fe] = 1;
        dfs(v, id);
        return;
    }
}

void solve() {
    co = 0;
    int n, m;
    cin >> n >> m;
    lu.clear();
    vis.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
    vector<int> in(n + 1);
    ed.assign(m + 1, {0, 0});
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        ed[i] = {u, v};
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
        in[v]++;
        in[u]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] % 2) {
            q.push(i);
        }
    }
    int idx = m;
    while (q.size()) {
        int u = q.front();
        q.pop();
        int v = q.front();
        q.pop();
        g[u].emplace_back(v, ++idx);
        g[v].emplace_back(u, idx);
        ed.emplace_back(u, v);
    }
    del.assign(ed.size(), 0);
    mp.assign(ed.size(), 0);

    for (int x = 1; x <= n; x++) {
        for (auto &[v, id] : g[x]) {
            if (!del[id]) {
                vis[x] = 1;
                dfs(v, id);
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << mp[i] << " \n"[i == m];
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