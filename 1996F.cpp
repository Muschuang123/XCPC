#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    i64 ans = 0;
    auto check = [&](int mid) {
        i64 res = 0;
        i64 need = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] >= mid) {
                int mul = (a[i] - mid) / b[i] + 1;
                int t = a[i] - (a[i] - mid) / b[i] * b[i];
                res += 1LL * (t + a[i]) * mul / 2;
                need += mul;
                if (t - b[i] >= mid) {
                    res += t - b[i];
                    need++;
                }
            }
        }
        if (need <= k) {
            ans = max(ans, res);
        }
        return need;
    };

    int l = 0, r = *max_element(a.begin() + 1, a.end()) + 1;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (check(mid) <= k) {
            r = mid;
        } else {
            l = mid;
        }
    }

    // cout << r << '\n';
    // cout << check(r) << '\n';
    // cout << k << '\n';

    k -= check(r);
    for (int i = 1; i <= n; i++) {
        if (a[i] >= r) {
            a[i] -= (a[i] - r) / b[i] * b[i] + b[i];
        }
    }

    // include a[0] = 0
    int mx = *max_element(a.begin(), a.end());

    // cout << k << '\n';
    // cout << mx << '\n';
    // cout << ans << '\n';

    ans += 1LL * k * mx;
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