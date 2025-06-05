// 最小生成树 kruskal
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct edg {
    int u, v, w;
};

bool operator<(const edg &x, const edg &y) {
    return x.w > y.w;
}

int n, m;
vector<int> fa;
// vector<int> g[5003];

int fin(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = fin(fa[x]);
}

void merg(int x, int y) {
    fa[fin(x)] = fin(y);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    fa.resize(n + 1);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    // for (int i = 1; i <= n; i++)
    //     g[i].clear();

    priority_queue<edg> q;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        q.push({u, v, w});
    }

    int ans = 0;
    while (q.size()) {
        edg x = q.top();
        if (fin(x.u) != fin(x.v)) {
            ans += x.w;
            merg(x.u, x.v);
        }
        q.pop();
    }
    int father = fin(1);
    for (int i = 2; i <= n; i++) {
        if (father != fin(i)) {
            cout << "orz";
            return 0;
        }
    }

    cout << ans;

    return 0;
}