#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    i64 x, k;
    cin >> x >> k;
    if (x == 1) {
        cout << 1 << '\n';
        return 0;
    }
    i64 ans = k + 1;
    while (x > 0 && k > 0) {
        i64 t = sqrtl(x);
        k--;
        ans++;
        if (t == 1) {
            break;
        }
        if (t * t != x) {
            ans += k;
        }
        x = t;
    }
    cout << ans << '\n';

    return 0;
}