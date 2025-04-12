#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// implemention: 除自环的边数 + 单独环个数

set<int> g[128];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        g[s[i]].insert(t[i]);
        if (g[s[i]].size() > 1) {
            // 一个字符要变成两个字符，不合法
            cout << -1 << '\n';
            return 0;
        }
    }

    int in[128] = {0};
    int selfcir[128] = {0};
    for (int i = 'a'; i <= 'z'; i++) {
        for (auto &v : g[i]) {
            if (v == i) {
                selfcir[i] = 1;
            } else {
                in[v]++;
                ans++;
            }
        }
    }
    
    // 去除自环
    for (int i = 'a'; i <= 'z'; i++) {
        if (selfcir[i]) {
            g[i].clear();
        }
    }

    // 拓扑排序，把带树状结构的环都染色，
    queue<int> q;
    int fl1 = 1;
    int col[128] = {0};
    for (int i = 'a'; i <= 'z'; i++) {
        if (in[i] == 0) {
            q.push(i);
            col[i] = 1;
            if (!selfcir[i]) {
                fl1 = 0;
            }
        }
    }

    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto &v : g[x]) {
            col[v] = 1;
            if (--in[v] == 0) {
                q.push(v);
            }
        }
    }

    // 然后 DFS 扩散颜色，
    int vis[128] = {0};
    function<void(int)> dfs = [&](int x) {
        if (vis[x]) {
            return;
        }
        col[x] = 1;
        vis[x] = 1;
        for (auto &v : g[x]) {
            dfs(v);
        }
    };

    for (int i = 'a'; i <= 'z'; i++) {
        if (col[i] && !vis[i]) {
            dfs(i);
        }
    }

    // 最后检查没有被染色的环的个数
    int fl2 = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 'a'; i <= 'z'; i++) {
        if (!col[i]) { // && !(g[i].size() == 1 && *g[i].begin() == i)
            ans++;
            dfs(i);
            fl2 = 1;
        }
    }

    if (fl1 && fl2) {
        cout << -1 << '\n';
        return 0;
    }

    cout << ans << '\n';

    return 0;
}