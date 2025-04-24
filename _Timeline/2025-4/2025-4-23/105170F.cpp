#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 2e5 + 5;
vector<int> g[maxn];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
    vector<array<int, 5>> a(m + 1);
    multiset<int> ss;
    for (int i = 1; i <= m; i++) {
        int u, v, x, y, z;
        cin >> u >> v >> x >> y >> z;
        a[i] = {u, v, x, y, z};
        ss.insert(max({x, y, x + y + z + 1 >> 1}));
        g[u].push_back(i);
        g[v].push_back(i);
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        int cur = 0;
        vector<int> tp;
        for (auto &e : g[i]) {
            auto &[u, v, x, y, z] = a[e];
            int res = max({x, y, x + y + z + 1 >> 1});
            if (i == u) {
                if (x + z > y) {
                    cur = max(cur, x + z);
                    tp.push_back(res);
                    ss.erase(ss.find(res));
                }
            } else {
                if (y + z > x) {
                    cur = max(cur, y + z);
                    tp.push_back(res);
                    ss.erase(ss.find(res));
                }
            }
        }
        if (ss.empty() || cur > *ss.rbegin()) {
            ans.push_back(i);
        }
        for (auto &e : tp) {
            ss.insert(e);
        }
    }
    cout << ans.size() << '\n';
    for (auto &e : ans) {
        cout << e << ' ';
    }
    if (ans.size()) {
        cout << '\n';
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