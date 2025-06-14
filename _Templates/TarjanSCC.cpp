// g: 原始图  |  h: 缩点图
vector<int> g[maxn], h[maxn];
// a: 原始点权  |  b: 缩点点权
// int a[maxn], b[maxn];

struct Tarjan {
    int n;
    int dfn[maxn], low[maxn], dfnknt;
    int stk[maxn], instk[maxn], top;
    int scc[maxn], sz[maxn], cnt;

    void tj(int x) {
        low[x] = dfn[x] = ++dfnknt;
        stk[++top] = x;
        instk[x] = 1;
        for (auto &v : g[x]) {
            if (!dfn[v]) {
                tj(v);
                low[x] = min(low[x], low[v]);
            } else if (instk[v]) {
                low[x] = min(low[x], dfn[v]);
            }
        }
        if (dfn[x] == low[x]) {
            int v;
            cnt++;
            do {
                v = stk[top--];
                instk[v] = 0;
                scc[v] = cnt;
                sz[cnt]++;
            } while (v != x);
        }
    }

    void init(int _n) {
        n = _n;
        dfnknt = cnt = 0;
        for (int i = 1; i <= n; i++) {
            dfn[i] = low[i] = 0;
            scc[i] = sz[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) {
                tj(i);
            }
        }
    }

    void rebuild() {
        for (int i = 1; i <= cnt; i++) {
            h[i].clear();
            // b[i] = 0;
        }
        for (int x = 1; x <= n; x++) {
            // b[scc[x]] += a[x];
            for (auto &v : g[x]) {
                if (scc[x] != scc[v]) {
                    h[scc[x]].push_back(scc[v]);
                }
            }
        }
        for (int i = 1; i <= cnt; i++) {
            auto &H = h[i];
            sort(H.begin(), H.end());
            H.erase(unique(H.begin(), H.end()), H.end());
        }
    }
} tar;