#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int N = 200005;
int n;
int tr1[N], tr2[N];
void add(int k, int val, int op) {
    if (op == 1) {
        for (int i = k; i < N; i += (i & -i)) tr1[i] += val;
    } else {
        for (int i = k; i < N; i += (i & -i)) tr2[i] += val;
    }
}
int query(int k, int op) {
    int res = 0;
    if (op == 1) {
        for (int i = k; i > 0; i -= (i & -i)) res += tr1[i];
    } else {
        for (int i = k; i > 0; i -= (i & -i)) res += tr2[i];
    }
    return res;
}
int pos1[N], pos2[N], a[N], b[N];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], pos1[a[i]] = i;
    for (int i = 1; i <= n; i++) cin >> b[i], pos2[b[i]] = i;
    int l = 1;
    int ans = 0;
    for (int r = 1; r <= n; r++) {
        add(pos1[r], 1, 1);
        add(pos2[r], 1, 2);
        int q1 = query(pos1[r], 1);
        int q2 = query(pos2[r], 2);
        while (l < r && q1 != q2) {
            add(pos1[l], -1, 1);
            add(pos2[l], -1, 2);
            q1 = query(pos1[r], 1);
            q2 = query(pos2[r], 2);
            l++;
        }

        ans += r - l + 1;

    }
    cout << ans;
}