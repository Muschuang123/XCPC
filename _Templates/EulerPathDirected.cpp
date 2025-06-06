struct EulerPath {
    vector<int> g[maxn];
    int indeg[maxn], outdeg[maxn];
    int val[maxm];
    bool vis[maxm];
    vector<int> vpa, epa;
    vector<pair<int, int>> e;

    int n, m;
    void init(int _n, int _m) {
        n = _n, m = _m;
        for (int i = 0; i <= n; i++) {
            g[i].clear();
            indeg[i] = outdeg[i] = 0;
        }
        for (int i = 0; i <= m; i++) {
            val[i] = vis[i] = 0;
        }
        vpa.clear();
        epa.clear();
        e.assign(m + 1, {0, 0});
    }
    // 1-index id
    void add(int x, int y, int id) {
        g[x].push_back(id);
        val[id] = x ^ y;
        outdeg[x]++;
        indeg[y]++;
        e[id] = {x, y};
    }

    void dfs(int x) {
        vector<int> stk;
        stk.push_back(x);
        while (!stk.empty()) {
            x = stk.back();
            while (!g[x].empty()) {
                int id = g[x].back();
                g[x].pop_back();
                if (!vis[id]) {
                    vis[id] = true;
                    x = val[id] ^ x;
                    stk.push_back(x);
                }
            }
            vpa.push_back(x);
            stk.pop_back();
        }
    }

    bool work(int st = 1) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (indeg[i] != outdeg[i]) {
                if (indeg[i] < outdeg[i]) {
                    st = i;
                }
                cnt += abs(indeg[i] - outdeg[i]);
                if (cnt > 2) {
                    return false;
                }
            }
        }
        dfs(st);
        bool isepa = (vpa.size() == m + 1);
        if (isepa) {
            map<i64, vector<int>> mp;
            for (int i = 1; i < e.size(); i++) {
                i64 x = e[i].first, y = e[i].second;
                i64 ke = x << 32 | y;
                mp[ke].push_back(i);
            }
            reverse(vpa.begin(), vpa.end());
            for (int i = 1; i < vpa.size(); i++) {
                i64 x = vpa[i - 1], y = vpa[i];
                i64 ke = x << 32 | y;
                epa.push_back(mp[ke].back());
                mp[ke].pop_back();
            }
        }
        return isepa;
    }
} ep;