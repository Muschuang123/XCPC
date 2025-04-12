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

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, d;
    cin >> n >> d;
    fa.resize(n + 1);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    
    vector<bool> vis(n + 1);
    int ch = 0;

    int la = 0;
    while (d--)
    {
        int u, v;
        cin >> u >> v;

        if (fin(u) == fin(v))
        {
            ch++;
        }

        vis[u] = 1;
        vis[v] = 1;
        merg(u, v);
        map<int, int> f;

        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
            {
                f[fin(i)]++;
            }
        }

        priority_queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] && fin(i) == i)
                q.push(f[i]);
        }

        int res = -1;
        for (int i = 0; i <= ch; i++)
        {
            res += q.top();
            q.pop();
            if (q.empty())
            {
                res += ch - i;
                break;
            }
        }
        la = max(la, res);

        cout << la << '\n';
    }

    return 0;
}