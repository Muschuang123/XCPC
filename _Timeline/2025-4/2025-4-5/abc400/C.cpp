#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    i64 n;
    cin >> n;
    i64 ans = 0;

    for (int i = 1; i <= 62; i++) {
        i64 a = 1LL << i;
        i64 l = 0, r = 1e9 + 7;
        while (l + 1 < r) {
            i64 mid = l + r >> 1;
            if ((i128)a * (i128)mid * (i128)mid <= (i128)n) {
                l = mid;
            } else {
                r = mid;
            }
        }
        ans += (l + 1) / 2;
    }

    cout << ans << '\n';

    return 0;
}