#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    i64 n, m;
    cin >> n >> m;
    i64 t = 1;
    i64 ans = 0;
    for (int i = 0; i <= m; i++) {
        ans += t;
        t = t * n;
        if (ans > 1e9) {
            cout << "inf" << '\n';
            return 0;
        }
    }
    cout << ans << '\n';

    return 0;
}