// https://acm.hdu.edu.cn/contest/problem?cid=1172&pid=1007
// 求树上路径 (u, v)，使得 LCM({u到v路径上的点权}) = x，的路径条数
// SOS DP 做法
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int n, X;
    cin >> n >> X;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> p;
    vector<int> cnt;
    int nX = X;
    for (int i = 2; i <= nX / i; i++) {
        if (nX % i == 0) {
            p.push_back(i);
            cnt.push_back(0);
            while (nX % i == 0) {
                nX /= i;
                cnt.back()++;
            }
        }
    }
    if (nX > 1) {
        p.push_back(nX);
        cnt.push_back(1);
    }
    int k = p.size();
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        int e;
        cin >> e;
        if (lcm(e, X) > X) {
            a[i] = -1;
        } else {
            for (int j = 0; j < k; j++) {
                int res = 0;
                while (e % p[j] == 0) {
                    e /= p[j];
                    res++;
                }
                if (res == cnt[j]) {
                    a[i] |= 1 << j;
                }
            }
        }
    }

    i64 ans = 0;
    vector<vector<i64>> dp(n + 1, vector<i64>(1 << k));
    function<void(int, int)> dfs = [&](int x, int fa) {
        for (int v : g[x]) {
            if (v == fa) {
                continue;
            }
            dfs(v, x);
        }

        // 截断，答案无效
        if (a[x] == -1) {
            return;
        }
        // 答案可能有效，在 a[x] 状态上产生贡献
        dp[x][a[x]] = 1;

        for (int v : g[x]) {
            if (v == fa) {
                continue;
            }
            auto sum = dp[x];
            // 超集
            for (int j = 0; j < k; j++) {
                for (int i = 0; i < (1 << k); i++) {
                    if (i >> j & 1 ^ 1) {
                        sum[i] += sum[i | 1 << j];
                    }
                }
            }
            // 查补集的超集，覆盖所有情况
            for (int i = 0; i < (1 << k); i++) {
                // i | a[x] : 过 x 点的话，x 是 1 的位不用补
                int c = i | a[x];
                ans += sum[c ^ (1 << k) - 1] * dp[v][i];
                // 并且 状态 i 转到 x 上之后就变成 状态 c了
                dp[x][c] += dp[v][i];
            }
        }
        
        // 单点构成的简单路径 也符合题意
        ans += a[x] == (1 << k) - 1;
    };
    dfs(1, 0);
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