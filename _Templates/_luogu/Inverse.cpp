#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<int> s;

void add(int x, int y) {
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

    cin >> n;
    s.resize(n + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> c = a;
    sort(c.begin() + 1, c.end());
    map<int, int> m;
    for (int i = 1; i <= n; i++) {
        m[c[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        a[i] = m[a[i]];
    }

    int ans = 0;
    for (int i = n; i >= 1; i--) {
        ans += ask(a[i] - 1);
        add(a[i], 1);
    }
    cout << ans;

    return 0;
}