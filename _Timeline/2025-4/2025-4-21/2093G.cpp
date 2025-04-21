#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 32 * 2e5;
// 2^30 > 1e9
const int w = 30;

struct Trie {
    static const int Tsz = 2;
    int ch[maxn][Tsz], mx[maxn];
    int idx = 0;

    Trie() {
        memset(ch, 0, sizeof(ch)), memset(mx, 0, sizeof(mx));
    }

    void insert(int x, int id) {
        int u = 0;
        for (int i = w; i >= 0; i--) {
            int v = x >> i & 1;
            if (!ch[u][v]) {
                ch[u][v] = ++idx;
            }
            u = ch[u][v];
            mx[u] = max(mx[u], id);
        }
    }

    int query(int x, int k) {
        int u = 0;
        int res = -1;
        for (int i = w; i >= 0; i--) {
            int v = x >> i & 1;
            int z = k >> i & 1;
            // x ^ y > k
            // k 这一位是 0 时，让 x ^ y 这一位是 1，可以做到 >
            if (!z && ch[u][v ^ 1]) {
                res = max(res, mx[ch[u][v ^ 1]]);
            }
            if (!ch[u][v ^ z]) {
                return res;
            }
            u = ch[u][v ^ z];
        }
        // x ^ y == k
        res = max(res, mx[u]);
        return res;
    }

    void clear() {
        for (int i = 0; i <= idx; i++) {
            mx[i] = 0;
            for (int j = 0; j < Tsz; j++) {
                ch[i][j] = 0;
            }
        }
        idx = 0;
    }
} T;

void solve() {
    T.clear();
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // 1 <= i == j <= n 构成答案 a[i] ^ a[j] == 0 >= k
    if (k == 0) {
        cout << 1 << '\n';
        return;
    }

    int ans = n + 1;
    for (int i = 1; i <= n; i++) {
        int res = T.query(a[i], k);
        if (res != -1) {
            ans = min(ans, i - res + 1);
        }
        T.insert(a[i], i);
    }

    cout << (ans == n + 1 ? -1 : ans) << '\n';
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