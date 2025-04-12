#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> g[200005];
int vis[200005];
int res = 0;

void dfs(int x) {
    vis[x] = 1;
    res++;
    for (auto &v : g[x]) {
        if (!vis[v])
            dfs(v);
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        vis[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        g[x].push_back(i);
        g[i].push_back(x);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (!vis[x]) {
            res = 0;
            dfs(x);
            ans += res;
        }
        cout << ans << " \n"[i == n];
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