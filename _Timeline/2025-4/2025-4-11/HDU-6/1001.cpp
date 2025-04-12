#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    i64 k, a, b, c;
    cin >> k >> a >> b >> c;
    vector<i64> vec = {a + b + c, a + b, b + c, a + c, a, b, c, 0};
    sort(vec.begin(), vec.end());
    cout << k - *--upper_bound(vec.begin(), vec.end(), k) << '\n';
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