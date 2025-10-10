// https://www.luogu.com.cn/problem/P2709
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int B;
i64 res = 0;
vector<int> c;

struct qu {
    int l, r, i;
};

bool operator<(const qu &a, const qu &b) {
    if (a.l / B != b.l / B) {
        return a.l < b.l;
    } else {
        if (a.l / B % 2) return a.r > b.r;
        return a.r < b.r;
    }
}

inline void add(int x) {
    res -= c[x] * c[x];
    c[x]++;
    res += c[x] * c[x];
}

inline void del(int x) {
    res -= c[x] * c[x];
    c[x]--;
    res += c[x] * c[x];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    B = sqrtl(n);
    c.resize(k + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<qu> q(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].i = i;
    }

    sort(q.begin() + 1, q.end());

    vector<i64> ans(m + 1);
    for (int i = 1, l = 1, r = 0; i <= m; i++) {
        while (l > q[i].l) add(a[--l]);
        while (r < q[i].r) add(a[++r]);
        while (l < q[i].l) del(a[l++]);
        while (r > q[i].r) del(a[r--]);
        ans[q[i].i] = res;
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}