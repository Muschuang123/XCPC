// 没测过
vector<int> g[maxn];
int sz[maxn];
int root, mis = maxn;

void getroot(int u, int f) {
    sz[u] = 1;
    int s = 0;
    for (int v : g[u]) {
        if (f == v) {
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