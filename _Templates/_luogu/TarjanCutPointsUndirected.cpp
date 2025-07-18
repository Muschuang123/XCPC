#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 2e4 + 4;
vector<int> g[maxn];
// low[u]​​：表示 u 或其子树中的节点通过最多一条回边（非树边）能追溯到的最小时间戳
// 多测必须清空这几个数组。
int dfn[maxn], low[maxn], cut[maxn];
int root = 1;
int dfnknt = 0;

void tj(int x) {
    dfn[x] = low[x] = ++dfnknt;
    int child = 0;
    for (auto &v : g[x]) {
        if (dfn[v]) {  // 已访问，是 dfn 更小的节点，直接从这个点转移 dfn
            low[x] = min(low[x], dfn[v]);
        } else {  // 未访问，属于 x 的子树，在 dfs 后 更新 low[x]
            tj(v);
            low[x] = min(low[x], low[v]);
            if (low[v] >= dfn[x]) {  // 这表明不通过 x，v 根本回不去
                child++;
                // 不是根节点 or 有超过两个孩子
                if (x != root || child > 1) {
                    cut[x] = 1;
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
            tj(i);
        }
    }

    cout << count(cut + 1, cut + 1 + n, 1) << '\n';
    for (int i = 1; i <= n; i++) {
        if (cut[i]) {
            cout << i << ' ';
        }
    }
    cout << '\n';

    return 0;
}