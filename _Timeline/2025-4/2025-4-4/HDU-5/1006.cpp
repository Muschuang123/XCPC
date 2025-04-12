#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int d, r, x, y;
    cin >> d >> r >> x >> y;
    x = abs(x), y = abs(y);
    if (y <= d) {
        cout << abs(x - r) << '\n';
    } else {
        cout << fabs(r - sqrtl((0 - x) * (0 - x) + (d - y) * (d - y))) << '\n';
    }
}

int main() {
    cout << fixed << setprecision(0);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}