// 这个板子没找到地方测。
// 可以参考：
// https://codeforces.com/contest/1986/problem/F
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 5e4 + 4;
vector<int> g[maxn];
// low[u]​​：表示 u 或其子树中的节点通过最多一条回边（非树边）能追溯到的最小时间戳
// 多测必须清空这几个数组。
int dfn[maxn], low[maxn], cut[maxn];
int ans, dfnknt, root = 1;

void tj(int u, int f) {
    dfn[u] = low[u] = ++dfnknt;
    int child = 0;
    for (auto &v : g[u]) {
        if (dfn[v] && v != f) {  // 已访问，是 dfn 更小的节点，直接从这个点转移 dfn
            low[u] = min(low[u], dfn[v]);
        } else if (!dfn[v]) {  // 未访问，属于 u 的子树，在 dfs 后 更新 low[u]
            tj(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) {  // 这表明不通过 x，v 根本回不去
                child++;
                // 不是根节点 or 有超过两个孩子
                if (u != root || child > 1) {
                    ans++;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            root = i;
            tj(i, 0);
        }
    }

    cout << ans << '\n';

    return 0;
}