// 树状数组
// 前缀和的单点修改与查询
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<int> s;

void add(int x, int y) {
    if (x == 0)
        return;
    while (x <= n) {
        s[x] += y;
        x += x & -x;
    }
}

int ask(int x) {
    int ans = 0;
    while (x) {
        ans += s[x];
        x -= x & -x;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int m;
    cin >> n >> m;
    s.resize(n + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        add(i, a[i] - a[i - 1]);
    }

    while (m--) {
        int op, x, y, k;
        cin >> op >> x;
        if (op == 1) {
            cin >> y >> k;
            add(x, k);
            add(y + 1, -k);
        }
        if (op == 2) {
            // cout << '\n';
            // for (int i = 1; i <= n; i++)
            //     cout << ask(i) << ' ';
            // cout << '\n';
            cout << ask(x) << '\n';
        }
    }

    return 0;
}