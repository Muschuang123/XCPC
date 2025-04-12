#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    int stx, sty, enx, eny;
    cin >> stx >> sty >> enx >> eny;

    auto check = [&](int x, int y) {
        return x >= 1 && x <= n && y >= 1 && y <= m;
    };

    vector<vector<int>> d(n + 1, vector<int>(m + 1, 1e9));
    vector<vector<int>> vis(n + 1, vector<int>(m + 1));
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> q;
    d[stx][sty] = 0;
    q.push({0, stx, sty});

    while (q.size()) {
        auto [TT, i, j] = q.top();
        q.pop();
        if (vis[i][j]) {
            continue;
        }
        vis[i][j] = 1; 
        for (auto &[dx, dy] : dir) {
            int x = i + dx, y = j + dy;
            int co = 0;
            if (check(x, y)) {
                if (a[x][y] == '#') {
                    co = 1;
                }
                if (d[x][y] > d[i][j] + co) {
                    d[x][y] = d[i][j] + co;
                    q.push({d[x][y], x, y});
                }
                x += dx, y += dy;
                if (check(x, y)) {
                    if (a[x][y] == '#') {
                        co = 1;
                    }
                    if (d[x][y] > d[i][j] + co) {
                        d[x][y] = d[i][j] + co;
                        q.push({d[x][y], x, y});
                    }
                }
            }
        }
    }
    cout << d[enx][eny] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}