#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    auto work = [&](int &x) {
        x++;
        x = (x - 1) % k + 1;
    };
    int x = 1;
    for (int i = 1; i <= n; i++) {
        if (m % k == 0) {
            work(x);
        }
        for (int j = 1; j <= m; j++) {
            cout << x << " \n"[j == m];
            work(x);
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