#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    cout << 1LL * a * b * c * d * e + 1LL * a * b * c * (d - 1) * d / 2 << '\n';
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