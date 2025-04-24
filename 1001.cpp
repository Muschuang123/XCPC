#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<int> b(k + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    int x = 1, y = m;
    int cur = 0;
    int ans = 0;
    while (x <= n) {
        for (int j = 1; j <= y; j++) {
            if (b[a[x][j]] == 0) {
                cur++;
            }
            b[a[x][j]]++;
        }

        while (y >= 0 && cur == k) {
            for (int i = 1; i <= x; i++) {
                if (b[a[i][y]] == 1) {
                    cur--;
                }
                b[a[i][y]]--;
            }
            y--;
        }
        ans += m - y;
        x++;
    }
    cout << ans << '\n';
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