// https://codeforces.com/contest/1946/problem/D
// 位运算好题
// 涉及到很多转化
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    // 转化为 < x
    x++;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] ^= a[i - 1];
    }

    int y = 0;
    int ans = -1;
    for (int j = 30; j >= 0; j--) {
        if (x >> j & 1) {
            y |= 1 << j;
            if (a[n] & y) {
                y ^= 1 << j;
                continue;
            }
            // 寻找 净空。
            int res = 0;
            for (int i = 1; i <= n; i++) {
                res += !(a[i] & y);
            }
            ans = max(ans, res);
            y ^= 1 << j;
        } else {
            y |= 1 << j;
        }
    }
    cout << ans << '\n';
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