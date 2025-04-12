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

        i64 sum = accumulate(a.begin(), a.end(), 0LL);

        // 其他根作为根时，其他和其他
        i64 ans = 0;
        for (int i = 0; i < a.size(); i++) {
            for (int j = i + 1; j < a.size(); j++) {
                ans += a[i] * a[j] * (sum - a[i] - a[j]);
            }
        }

        // 自己作为根时，其他和其他
        i64 res = 0;
        for (int i = 0; i < a.size(); i++) {
            res += a[i] * (sum - a[i]);
        }
        ans += res / 2;

        // 其他数作为根时，自己和其他
        for (int i = 0; i < a.size(); i++) {
            ans += a[i] * (sum - a[i]);
        }

        // 自己作为根时，自己和其他
        ans += sum;
        
        // 任意数作为根时，自己和自己
        ans += n;

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