#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int T = n / (m + 1);
    T = max(T, k);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i += T) {
        int cnt = 0;
        for (int j = 0; j < T && i + j <= n; j++) {
            a[i + j] = cnt++;
        }
    }
    // int cnt = 0;
    // for (int j = 0; j < T; j++) {
    //     a[n - j] = cnt++;
    // }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
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