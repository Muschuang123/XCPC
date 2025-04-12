#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) b[i] += a[i];
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];

    i64 ans = 0;
    for (int l = 1, r = 1; r <= n; r++) {
        while (l < r && b[l] != b[r]) {
            l++;
        }
        ans = max(ans, (a[r] - a[l - 1]) * (r - l + 1));
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