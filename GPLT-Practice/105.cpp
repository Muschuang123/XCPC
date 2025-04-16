#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 1e5 + 5;
vector<int> g[maxn];
// 1-female 2-male
int sex[maxn];

unordered_set<int> ss;
int vis[maxn];
int ok = 1;

void dfs(int x, int ag) {
    if (ag > 5) {
        return;
    }
    if (ss.count(x)) {
        ok = 0;
        return;
    }
    vis[x] = 1;
    ss.insert(x);
    for (auto &v : g[x]) {
        if (vis[v]) {
            continue;
        }
        dfs(v, ag + 1);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        int fu, mu;
        char se;
        cin >> a[i] >> se >> fu >> mu;
        sex[a[i]] = se == 'M' ? 2 : 1;
        if (fu != -1) {
            g[a[i]].push_back(fu);
            sex[fu] = 2;
        }
        if (mu != -1) {
            g[a[i]].push_back(mu);
            sex[mu] = 1;
        }
    }

    int k;
    cin >> k;
    while (k--) {
        int u, v;
        cin >> u >> v;
        if (sex[u] == sex[v]) {
            cout << "Never Mind\n";
        } else {
            ok = 1;
            dfs(u, 1);
            for (auto &e : ss) {
                vis[e] = 0;
            }
            dfs(v, 1);
            for (auto &e : ss) {
                vis[e] = 0;
            }
            cout << (ok ? "Yes" : "No") << '\n';
            ss.clear();
        }
    }

    return 0;
}