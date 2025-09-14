// O(nQlogn)
const int maxn =
    const int ran = 1e7 + 7; // 值域
vector<pair<int, int>> g[maxn];
int del[maxn]; // 节点是否被删除
int sz[maxn];  // 以当前节点为根树大小
int mis;       // 最小的 max(所有子树大小)
int sum;       // 当前子树的所有节点数
int root;      // 当前的根
int bu[ran];   // 信息 桶
int res[maxn]; // 已有点到重心的 信息
int tot;       // 点到重心的距离个数
int n, Q;      // n 个点，Q 次询问
int ask[maxn]; // Q 次询问内容
int ans[maxn]; // Q 次答案

void getroot(int u, int f) {
    sz[u] = 1;
    int s = 0;
    for (auto [v, w] : g[u]) {
        if (f == v || del[v]) {
            continue;
        }
        getroot(v, u);
        sz[u] += sz[v];
        s = max(s, sz[v]);
    }
    s = max(s, sum - sz[u]);
    if (s < mis) {
        mis = s;
        root = u;
    }
}

void getres(int u, int f, int d) {
    res[++tot] = d;
    for (auto [v, w] : g[u]) {
        if (v == f || del[v]) {
            continue;
        }
        getres(v, u, d + w);
    }
}

void calc(int u) {
    // 计算经过根 u 的路径
    del[u] = bu[0] = 1;
    queue<int> q;
    for (auto [v, w] : g[u]) {
        if (del[v]) {
            continue;
        }
        // 子树 v 各点 到 u 的 信息
        tot = 0;
        getres(v, u, w);
        // 枚举 信息 和询问，判定答案
        for (int i = 1; i <= tot; i++) {
            for (int j = 1; j <= Q; j++) {
                if (ask[j] >= res[i]) {
                    // 计算信息
                    ans[j] |= bu[ask[j] - res[i]];
                }
            }
        }
        // 记录这个子树的合法距离，让其他子树对着枚举
        for (int i = 1; i <= tot; i++) {
            if (res[i] < ran) {
                q.push(res[i]);
                bu[res[i]] = 1;
            }
        }
    }
    // 清空所有信息
    while (!q.empty()) {
        bu[q.front()] = 0;
        q.pop();
    }

    // 对 u 的子树继续分治
    for (auto [v, w] : g[u]) {
        if (del[v]) {
            continue;
        }
        mis = sum = sz[v];
        getroot(v, 0);
        calc(root);
    }
}

// main():
{
    cin >> n >> Q;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    for (int i = 1; i <= Q; i++) {
        cin >> ask[i];
    }
    mis = sum = n;
    getroot(1, 0);
    calc(root);
    for (int i = 1; i <= Q; i++) {
        cout << (ans[i] ? "YES" : "NO") << '\n';
    }
}