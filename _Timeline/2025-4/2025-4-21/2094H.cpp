#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 1e5 + 5;
vector<int> b[maxn];

void solve() {
    int n, Q;
    cin >> n >> Q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]].push_back(i);
    }
    while (Q--) {
        int k, l, r;
        cin >> k >> l >> r;
        i64 ans = 0;
        while (k > 1) {
            int mi = r + 1;
            for (int i = 1; i <= k / i; i++) {
                if (k % i == 0) {
                    auto it = lower_bound(b[k / i].begin(), b[k / i].end(), l);
                    if (it != b[k / i].end() && *it <= r) {
                        mi = min(mi, *it);
                    }
                    if (i == 1 || i * i == k) {
                        continue;
                    }
                    it = lower_bound(b[i].begin(), b[i].end(), l);
                    if (it != b[i].end() && *it <= r) {
                        mi = min(mi, *it);
                    }
                }
            }
            if (mi == r + 1) {
                ans += 1LL * (r - l + 1) * k;
                l = mi;
                break;
            } else {
                ans += 1LL * (mi - l) * k;
                while (k % a[mi] == 0) {
                    k /= a[mi];
                }
                ans += k;
                l = mi + 1;
            }
        }
        ans += r - l + 1;
        cout << ans << '\n';
    }

    for (int i = 1; i <= n; i++) {
        b[a[i]].clear();
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