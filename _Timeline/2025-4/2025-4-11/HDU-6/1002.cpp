#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 1e5 + 5;

struct SparseTable {
    int mx[maxn][25], lg[maxn];
    int n, a[maxn];

    void build() {
        lg[0] = -1;
        for (int i = 1; i <= n; i++) {
            mx[i][0] = a[i];
            lg[i] = lg[i / 2] + 1;
        }
        for (int i = 1; i <= lg[n]; i++) {
            for (int j = 1; j + (1 << i) - 1 <= n; j++) {
                mx[j][i] = max(mx[j][i - 1], mx[j + (1 << (i - 1))][i - 1]);
            }
        }
    }

    int query(int l, int r) {
        int len = lg[r - l + 1];
        return max(mx[l][len], mx[r - (1 << len) + 1][len]);
    }
} ST;

void solve() {
    i64 x;
    int &n = ST.n;
    cin >> n >> x;
    auto &a = ST.a;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ST.build();
    vector<i64> dif(n + 1);
    for (int i = 2; i <= n; i++) {
        dif[i] = abs(a[i] - a[i - 1]);
    }
    vector<i64> pre = dif;
    for (int i = 3; i <= n; i++) {
        pre[i] += pre[i - 1];
    }
    i64 sum = pre[n];

    if (sum <= x) {
        cout << 0 << '\n';
        return;
    }

    int ans = n + 1;
    for (int i = 1; i <= n; i++) {

        auto check = [&](int mid) {
            // [i, mid]
            i64 mx = ST.query(i, mid);
            i64 res = sum - (pre[mid] - pre[i]);
            if (i > 1) {
                res -= dif[i];
                res += abs(mx - a[i - 1]);
            }
            if (mid < n) {
                res -= dif[mid + 1];
                res += abs(mx - a[mid + 1]);
            }
            if (x == 6) {
                cout << "";
            }
            return res <= x;
        };

        int l = i - 1, r = n;
        while (l + 1 < r) {
            int mid = l + r >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        
        if (check(r)) {
            ans = min(ans, r - i + 1);
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