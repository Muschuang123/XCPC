#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> fa;

int fin(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = fin(fa[x]);
}

void merg(int x, int y)
{
    fa[fin(x)] = fin(y);
}

vector<int> g[100005];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    fa.resize(n + 1);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    vector<pair<int, int>> cus(k + 1);
    set<pair<int, int>> ed;
    for (int i = 1; i <= k; i++)
    {
        cin >> cus[i].first >> cus[i].second;
        if (cus[i].first > cus[i].second)
            swap(cus[i].first, cus[i].second);
        ed.insert(cus[i]);
    }

    vector<int> du(n + 1);
    for (auto &e : ed)
    {
        int u = e.first, v = e.second;
        g[u].push_back(v);
        g[v].push_back(u);
        du[u]++, du[v]++;
        merg(u, v);
    }

    queue<int> q;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (du[i] == 1 || du[i] == 0)
        {
            q.push(i);
            du[i] = -1;
            cnt++;
        }
    }

    int del = 0;
    vector<bool> vis(n + 1);
    while (q.size())
    {
        int x = q.front();
        vis[x] = 1;
        q.pop();
        for (auto &v : g[x])
        {
            du[v]--;
            if (!vis[v])
                del++;
            if (du[v] == 1 || du[v] == 0)
            {
                q.push(v);
                du[v] = -1;
                cnt++;
            }
        }
    }
    
    set<int> fn;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            fn.insert(fin(i));
    }

    if (cnt != n)
    {
        del += ed.size() - del - (ed.size() - del - (n - cnt - 1));
        del -= fn.size() - 1;
    }

    cout << k - del;
    
    return 0;
}

/*
5 5
1 2
1 3
2 4
3 4
4 5
*/