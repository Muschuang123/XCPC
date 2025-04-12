#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 1e6 + 6;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
i64 mp[maxn];

void solve() {
    int n, q;
    cin >> n >> q;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = a[i - 1] ^ mp[a[i]];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        if (a[r] ^ a[l - 1]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}

int main() {
    for (int i = 1; i <= 1e6; i++) {
        mp[i] = rnd();
    }
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}