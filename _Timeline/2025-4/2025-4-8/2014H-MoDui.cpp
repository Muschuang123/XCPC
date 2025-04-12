#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int odd = 0;
int B;
bool cnt[1000006];

struct Q {
    int l, r, i;
};

bool operator<(const Q &a, const Q &b) {
    if (a.l / B != b.l / B) {
        return a.l < b.l;
    } else {
        return a.r < b.r;
    }
}

inline void ch(int x) {
    cnt[x] = !cnt[x];
    odd += cnt[x] ? 1 : -1;
}

void solve() {
    int n, m;
    cin >> n >> m;
    B = sqrtl(n);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<Q> q(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].i = i;
    }

    sort(q.begin(), q.end());
    vector<int> ans(m + 1);
    for (int i = 1, l = 1, r = 0; i <= m; i++) {
        while (l > q[i].l) ch(a[--l]);
        while (r < q[i].r) ch(a[++r]);
        while (l < q[i].l) ch(a[l++]);
        while (r > q[i].r) ch(a[r--]);
        ans[q[i].i] = odd;
    }

    for (int i = 1; i <= m; i++) {
        if (ans[i]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    // 多测值域不清空，糖
    for (int i = 1; i <= n; i++) {
        if (cnt[a[i]]) {
            ch(a[i]);
        }
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