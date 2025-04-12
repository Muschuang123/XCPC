#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    i64 n, k, x;
    cin >> n >> k >> x;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    i64 sum = accumulate(a.begin() + 1, a.end(), 0LL);
    k -= x / sum;
    x %= sum;
    if (x) k--;
    else x = sum;
    i64 res = 0;
    int mi = 0;
    for (int i = n; i >= 1; i--) {
        res += a[i];
        if (res >= x)
        {
            mi = i;
            break;
        }
    }
    cout << max(0LL, k * n + mi) << '\n';
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