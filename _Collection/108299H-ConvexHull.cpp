// https://ac.nowcoder.com/acm/contest/108299/H
// 公路升级，升级次数变化，升级权重不同，问升级后最优
// 把 边 权 看做一次函数 用 (k, b) 做下凸包，查询的时候二分
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<i64> ua(m + 1), va(m + 1), ta(m + 1), wa(m + 1);
    vector<vector<int>> g(n + 1), h(n + 1);
    for (int i = 1; i <= m; i++) {
        cin >> ua[i] >> va[i] >> ta[i] >> wa[i];
        g[ua[i]].push_back(i);
        h[va[i]].push_back(i);
    }

    const i64 inf = 2e18;

    // dij1 : from 1 .
    priority_queue<pair<i64, int>> pq;
    vector<i64> d1(n + 1, inf);
    d1[1] = 0;
    pq.emplace(0, 1);
    while (pq.size()) {
        auto [D, x] = pq.top();
        pq.pop();
        D = -D;
        if (D > d1[x]) {
            continue;
        }
        for (int e : g[x]) {
            if (d1[va[e]] > D + ta[e]) {
                d1[va[e]] = D + ta[e];
                pq.emplace(-d1[va[e]], va[e]);
            }
        }
    }

    // dij2 : from n .
    vector<i64> d2(n + 1, inf);
    d2[n] = 0;
    pq.emplace(0, n);
    while (pq.size()) {
        auto [D, x] = pq.top();
        pq.pop();
        D = -D;
        if (D > d2[x]) {
            continue;
        }
        for (int e : h[x]) {
            if (d2[ua[e]] > D + ta[e]) {
                d2[ua[e]] = D + ta[e];
                pq.emplace(-d2[ua[e]], ua[e]);
            }
        }
    }

    // 找出可达边，升级的对象
    // T次 升级的之后的答案 就是 d1[u] + d2[v] + t[i] - w[i] * T
    // 转化为 一次方程， y = kx + b，存住 (k, b)
    // 单调栈建凸包，去掉不能升级到的边，二分

    vector<pair<i64, i64>> ed;
    for (int i = 1; i <= m; i++) {
        if (d1[ua[i]] != inf && d2[va[i]] != inf) {
            ed.emplace_back(-wa[i], d1[ua[i]] + d2[va[i]] + ta[i]);
        }
    }
    // 在第二象限建凸包，斜率从原点向外单调递减
    sort(ed.begin(), ed.end(), greater<>());

    vector<pair<i64, i64>> tb;
    // 注意边界情况，不升级 (题目已经保证 存在路径 1 -> n，放心 emplace)
    tb.emplace_back(0, d1[n]);
    for (auto [k, b] : ed) {
        while (tb.size() > 1) {
            // 现在最左边的点
            auto [k1, b1] = tb[tb.size() - 1];
            // 第二左边的点
            auto [k2, b2] = tb[tb.size() - 2];
            // 不知道 b 的大小关系，但是知道 k 的，利用这个转化为交叉相乘计算
            // (k1 - k) / (b1 - b) >= (k2 - k1) / (b2 - b1)
            // 1 / ((b1 - b) * (k2 - k1)) >= 1 / ((b2 - b1) * (k1 - k))
            // (b1 - b) * (k2 - k1) <= (b2 - b1) * (k1 - k)
            if ((__int128_t)(b1 - b) * (k2 - k1) >= (__int128_t)(b2 - b1) * (k1 - k)) {
                tb.pop_back();
            } else {
                break;
            }
        }
        tb.emplace_back(k, b);
    }

    i64 T;
    auto f = [&](int i) -> i64 {
        return tb[i].first * T + tb[i].second;
    };

    int Q;
    cin >> Q;
    while (Q--) {
        cin >> T;
        int l = 0, r = tb.size();
        while (l + 1 < r) {
            int mid = l + r >> 1;
            if (f(mid - 1) >= f(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << f(l) << '\n';
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