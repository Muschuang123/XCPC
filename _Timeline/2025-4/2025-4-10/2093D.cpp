#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    while (q--) {
        string op;
        cin >> op;
        if (op == "->") {
            int x, y;
            cin >> x >> y;
            i64 ans = 1, cur = 1LL << 2 * n;
            while (cur > 0) {
                i64 len = sqrtl(cur);
                if (len >= x && len >= y) {
                    ans += 0 * cur;
                } else if (len < x && len < y) {
                    ans += 1 * cur;
                } else if (len < x && len >= y) {
                    ans += 2 * cur;
                } else {
                    ans += 3 * cur;
                }
                x = (x - 1) % len + 1;
                y = (y - 1) % len + 1;
                // cout << ans << ' ' << cur << '\n';
                cur /= 4;
            }
            cout << ans << '\n';
        } else if (op == "<-") {
            i64 d;
            cin >> d;
            i64 x = 1, y = 1;
            i64 cur = 1LL << 2 * n;
            while (cur > 0) {
                i64 len = sqrtl(cur);
                if (3 * cur < d) {
                    x += 0;
                    y += len;
                    cout << "";
                } else if (2 * cur < d) {
                    x += len;
                    y += 0;
                    cout << "";
                } else if (cur < d) {
                    x += len;
                    y += len;
                    cout << "";
                }
                // cout << cur << ' ' << x << ' ' << y << ' ' << d << '\n';
                d = (d - 1) % cur + 1;
                cur /= 4;
            }
            cout << x << ' ' << y << '\n';
        }
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