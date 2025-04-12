#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<i64> a(n + 1);
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        a[x]++;
    }

    vector<i64> res(n + 2), suf(n + 2);
    for (int i = n; i >= 0; i--) {
        suf[i] = suf[i + 1] + a[i];
        res[i] = res[i + 1] + a[i] * (min(i, n - 1) - n + 1);
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (res[n - i] + suf[n - i] * min(i, n - 1)) * a[i];
        if (n - i <= i) {
            ans -= (2 * min(i, n - 1) - n + 1) * a[i];
        }
        cout << "";
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