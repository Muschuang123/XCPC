vector<int> g[maxn];
int dia = 0;
int dp[maxn]; // dp[u]: 以 u 为根的子树中，从 u 出发的最长路径。
// 对于树的直径，实际上是可以通过枚举从某个节点出发不同的两条路径相加的最大值求出
// 所以 dp[u] = max(dp[u], dp[v] + w(u, v))
// 在更新 dp[u] 之前，dia = max(dia, dp[u] + dp[v] + w(u, v)) 算答案
void dfs(int u, int fa) {
    for (int v : g[u]) {
        if (v == fa) {
            continue;
        }
        dfs(v, u);
        dia = max(dia, dp[u] + dp[v] + 1);
        dp[u] = max(dp[u], dp[v] + 1);
    }
}