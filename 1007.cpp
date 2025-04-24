#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<i64> t = {1, 2, 3, 4, 6, 8, 16};
i64 g = 1;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<i64> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) {
        i64 u, v;
        cin >> u >> v;
        u *= g;
        u /= v;
        a[i] = u;
        a[i] += a[i - 1];
        // cout << u << " \n"[i == n];
    }
    for (int i = 1; i <= m; i++) {
        i64 u, v;
        cin >> u >> v;
        u *= g;
        u /= v;
        b[i] = u;
        b[i] += b[i - 1];
        // cout << u << " \n"[i == m];
    }

    i64 ans = 0;
    int p1 = 0, p2 = 0;
    while (p1 < n && p2 < m) {
        if (a[p1] == b[p2]) {
            ans++;
            p1++, p2++;
        } else if (a[p1] < b[p2]) {
            p1++;
        } else if (a[p1] > b[p2]) {
            p2++;
        }
    }
    cout << ans << '\n';
}

int main() {
    for (auto &e : t) {
        g = lcm(g, e);
    }
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}