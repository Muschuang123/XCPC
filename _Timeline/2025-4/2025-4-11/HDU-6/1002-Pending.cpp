#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    i64 n, x;
    cin >> n >> x;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    auto check = [&](int mid) {
        priority_queue<i64> q;
        for (int i = 1; i <= )
    };

    int l = -1, r = n;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
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