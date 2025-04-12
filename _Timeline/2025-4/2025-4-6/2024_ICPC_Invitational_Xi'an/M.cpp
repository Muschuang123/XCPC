#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == sqrtl(k)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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