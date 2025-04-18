#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 1e5 + 5;

struct edge {
    int v, w;
};

vector<edge> g[maxn];
i64 cnt = 0;
int s, t;
i64 ans = 0;

vector<int> st;
int vis[maxn];
i64 res[maxn];

void dfs(int x, int fa) {
    st.push_back(x);
    if (x == t) {
        ans = cnt;
        for (auto &e : st) {
            vis[e] = 1;
        }
    }
    i64 cur = 0;
    for (auto &[v, w] : g[x]) {
        if (v == fa) {
            res[x] += w;
            continue;
        }
        res[v] = w;
        cnt += w;
        dfs(v, x);
        cur += max(0LL, res[v]);
        cnt -= w;
    }
    res[x] += cur;
    st.pop_back();
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        vis[i] = 0;
        res[i] = 0;
    }

    for (int i = 1; i < n; i++) {
        int u, v, p, q;
        cin >> u >> v >> p >> q;
        g[u].push_back({v, p});
        g[v].push_back({u, q});
    }
    cin >> s >> t;
    dfs(s, 0);
    i64 sum = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            for (auto &[v, w] : g[i]) {
                if (!vis[v]) {
                    sum += max(0LL, res[v]);
                }
            }
        }
    }
    cout << sum + ans << '\n';
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