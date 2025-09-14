// 计算树的直径值 dp 法，负边权可用
vector<int> g[maxn];
int dia = 0;
int dp[maxn]; // dp[u]: 以 u 为根的子树中，从 u 出发的最长路径。
// 对于树的直径，实际上是可以通过枚举从某个节点出发不同的两条路径相加的最大值求出
// 所以 dp[u] = max(dp[u], dp[v] + w(u, v))
// 在更新 dp[u] 之前，dia = max(dia, dp[u] + dp[v] + w(u, v)) 算答案
void calcDiameter(int u, int f) {
    for (int v : g[u]) {
        if (v == f) continue;
        calcDiameter(v, u);
        dia = max(dia, dp[u] + dp[v] + 1);
        dp[u] = max(dp[u], dp[v] + 1);
    }
}

// 找到具体的直径，负边权不可用
// 直接调用 initDiameter(int n)
// 第一次 dfs 找到最远的点
// 第二次 dfs 找出直径的两个端点
// 第三次 dfs 找到两个端点之间的连线
vector<int> g[maxn];
int dep[maxn], far1, far2;
vector<int> diaPath;
void calcDiameter(int u, int f) {
    for (int v : g[u]) {
        if (v == f) continue;
        dep[v] = dep[u] + 1;
        if (dep[far1] < dep[v]) far1 = v;
        calcDiameter(v, u);
    }
}
void findDiameter(int u, int f) {
    diaPath.push_back(u);
    if (u == far2) {
        far2 = -1;
        return;
    }
    for (int v : g[u]) {
        if (v == f) continue;
        findDiameter(v, u);
        if (far2 == -1) return;
    }
    diaPath.pop_back();
}
void initDiameter(int n) {
    diaPath.clear();
    far1 = far2 = dep[1] = 0;
    calcDiameter(1, 0);
    dep[far1] = 0;
    far2 = far1;
    calcDiameter(far1, 0);
    findDiameter(far1, 0);
}