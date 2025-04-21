#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 读题占模太高

void solve() {
    int n, m;
    cin >> m >> n;
    vector<string> a(m + 1);
    vector<vector<string>> b(n + 1, vector<string>(m + 1));
    for (int j = 1; j <= m; j++) {
        cin >> a[j];
    }
    int res = 0;
    vector<int> vis(m + 1);
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
            if (b[i][j] == a[j]) {
                cnt++;
                vis[j] = 1;
            }
        }
        res = max(res, cnt);
    }

    // cout << res << '\n';
    if (count(vis.begin() + 1, vis.end(), 0)) {
        cout << -1 << '\n';
    } else {
        cout << 3 * m - res * 2 << '\n';
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