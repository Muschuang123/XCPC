#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    auto check = [&](int mid) {
        int res = 0, cur = 0;
        vector<int> cnt(n + 9);
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (a[i] > n + 5) {
                continue;
            }
            cnt[a[i]]++;
            q.push(a[i]);
            if (cur == a[i]) {
                while (cnt[cur] != 0) {
                    cur++;
                }
            }
            if (cur >= mid) {
                while (q.size()) {
                    cnt[q.front()]--;
                    q.pop();
                }
                cur = 0;
                res++;
            }
        }
        return res >= k;
    };

    int l = 0, r = n + 10;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << '\n';
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