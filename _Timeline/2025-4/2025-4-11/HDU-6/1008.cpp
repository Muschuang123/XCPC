#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int mod = 1e9 + 7;

i64 ksm(i64 a, i64 n) {
    i64 ans = 1;
    a %= mod;
    while (n) {
        if (n & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

int inv2 = ksm(2, mod - 2);

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    // sort(a.begin() + 1, a.end(), greater<>());

    i64 ans = 1;
    for (int i = 2; i <= n; i++) {
        ans = (ans * (i - 1) % mod * i % mod * inv2) % mod;
    } 

    i64 res = 0;
    for (int i = 2; i <= n; i++) {
        res = (res + a[i] * a[i - 1]) % mod;
        a[i] = (a[i] + a[i - 1]) % mod;
    }
    cout << res << ' ' << ans << '\n';
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