#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<i64> a(m);
    for (int i = 0; i < m; i++) {
        a[i] = n / m + (n % m >= i);
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