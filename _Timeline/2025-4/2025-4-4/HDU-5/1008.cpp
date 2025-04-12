#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 1e6 * 26 / 2 > C(26, 13)
// >= 26 时，一定有：
// 从 n 中取两组不相同的数，每组 n/2 个，他们的和相同
// 把他们共同位置的数去掉，和仍然相同，即 YES

// bitset<(size_t)(1e6 * 25 + 7)> f[26];
bool f[26][(size_t)(1e6 * 25 + 7)];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n >= 26) {
        cout << "YES\n";
        return;
    }

    vector<int> sum(1 << n);
    // vector<unordered_set<int>> f(n + 1);
    for (int i = 1; i < (1 << n); i++) {
        int p = __lg(i);
        sum[i] = sum[i - (1 << p)] + a[p + 1];
        int bit = __builtin_popcount(i);
        // if (f[bit].count(sum[i])) {
        if (f[bit][sum[i]]) {
            for (int j = 1; j <= i; j++) {
                f[__builtin_popcount(j)][sum[j]] = 0;
            }
            cout << "YES\n";
            return;
        }
        // f[bit].insert(sum[i]);
        f[bit][sum[i]] = 1;
    }

    for (int i = 1; i < (1 << n); i++) {
        f[__builtin_popcount(i)][sum[i]] = 0;
    }

    cout << "NO\n";
    return;
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