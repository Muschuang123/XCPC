#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * 层序遍历 + 分奇偶层，BFS实现 + father判定
 * 最后一个节点和最后一个节点的 father 有可能相差 2 ，改一下
 */ 

const int maxn = 2e5 + 5;

vector<int> g[maxn];

vector<int> pri;
vector<int> np;
bool not_prime[maxn];
void primer(int n)
{
    not_prime[0] = not_prime[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!not_prime[i])
            pri.push_back(i);
        for (int j : pri)
        {
            if (i * j > n)
                break;
            not_prime[i * j] = true;
            if (i % j == 0)
                break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (not_prime[i])
            np.push_back(i);
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<pair<int, int>> q;
    vector<int> res(n + 1);
    int cntj = 1, cnto = 0;
    vector<bool> ji(n + 1);
    int cnt = 0;
    q.push({1, 0});
    while (q.size())
    {
        auto [x, fa] = q.front();
        q.pop();
        if (!ji[fa])
        {
            ji[x] = 1;
            res[x] = 2 * cntj++;
        }
        else
        {
            res[x] = 2 * n - 2 * cnto++;
        }
        cnt++;
        if (cnt == n)
        {
            res[x] = res[fa] - 1;
        }
        for (auto &v : g[x])
            if (v != fa)
                q.push({v, x});
    }

    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << " \n"[i == n];
    }
}

signed main()
{
    primer(2e5);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}