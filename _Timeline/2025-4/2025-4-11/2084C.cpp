#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<int> idx(n + 1);
    for (int i = 1; i <= n; i++) {
        idx[b[i]] = i;
    }

    vector<pair<int, int>> ans;
    int fl = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) {
            if ((!fl || i == n / 2 + 1) && n % 2) {
                fl = 1;
                if (i == n / 2 + 1) {
                    continue;
                } else {
                    ans.emplace_back(i, n / 2 + 1);
                    swap(a[i], a[n / 2 + 1]);
                    swap(b[i], b[n / 2 + 1]);
                    idx[b[i]] = i;
                    idx[b[n / 2 + 1]] = n / 2 + 1;
                }
            } else {
                cout << -1 << '\n';
                return;
            }
        } else if (b[i] == a[idx[a[i]]]) {
            if (idx[a[i]] == n + 1 - i || n % 2 && i == n / 2 + 1) {
                continue;
            } else {
                int t = idx[a[i]];
                ans.emplace_back(t, n + 1 - i);
                swap(a[t], a[n + 1 - i]);
                swap(b[t], b[n + 1 - i]);
                idx[b[t]] = t;
                idx[b[n + 1 - i]] = n + 1 - i;
            }
        } else {
            cout << -1 << '\n';
            return;
        }
    }

    cout << ans.size() << '\n';
    for (auto &[f, s] : ans) {
        cout << f << ' ' << s << '\n';
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