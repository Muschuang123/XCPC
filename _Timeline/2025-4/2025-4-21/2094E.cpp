#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(30);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 0; j < 30; j++) {
            b[j] += a[i] >> j & 1;
        }
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        i64 res = 0;
        for (int j = 0; j < 30; j++) {
            if (a[i] >> j & 1) {
                res += (n - b[j]) * (1LL << j);
            } else {
                res += b[j] * (1LL << j);
            }
        }
        ans = max(ans, res);
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