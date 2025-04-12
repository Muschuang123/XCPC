#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    i64 n;
    cin >> n;
    i64 sum = n * (n + 1) / 2;
    i64 sq = sqrtl(sum);
    if (sum == sq * sq) {
        cout << -1 << '\n';
        return;
    }
    for (i64 i = 1; i <= n; i++) {
        i64 pre = i * (i + 1) / 2;
        i64 sqr = sqrtl(pre);
        if (sqr * sqr == pre) {
            cout << i + 1 << ' ' << i << ' ';
            i++;
        } else {
            cout << i << ' ';
        }
    }
    cout << '\n';
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