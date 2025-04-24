#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        int l;
        cin >> l;
        for (int j = 1; j <= l; j++) {
            int x;
            cin >> x;
            a[i][x] = 1;
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << a[i][j] << " \n"[j == m];
    //     }
    // }
    // cout << flush;

    auto bfs = [&](int L) {
        int ans = 1e9;
        queue<array<int, 3>> q;
        vector<vector<int>> vis(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            if (a[i][1]) {
                continue;
            }
            q.push({1, i, 1});
            vis[i][1] = 1;
        }
        while (q.size()) {
            auto [d, x, y] = q.front();
            q.pop();
            if (y == m) {
                ans = min(ans, d);
            }
            for (auto &[dx, dy] : dir) {
                int tx = x + dx, ty = y + dy;
                if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && 
                        !vis[tx][ty] && !a[tx][ty]) {
                    q.push({d + 1, tx, ty});
                    vis[tx][ty] = 1;
                }
            }
        }
        return ans;
    };

    cout << bfs(1) << '\n';
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