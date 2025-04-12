#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> g[10004];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) g[i].clear();

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ok = 1;
    vector<int> vis(n + 1, -1);
    queue<int> q;
    vis[1] = 0;
    q.push(1);
    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (auto &v : g[x])
        {
            if (vis[v] == -1)
            {
                q.push(v);
                vis[v] = vis[x] ^ 1;
            }
            else if (vis[x] == vis[v])
            {
                ok = 0;
                break;
            }
        }
        if (!ok)
            break;
    }
    
    if (!ok)
    {
        cout << "Alice" << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << "1 2" << endl;
            int v, c;
            cin >> v >> c;
        }
    }
    else
    {
        cout << "Bob" << endl;
        queue<int> v0, v1;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
                v1.push(i);
            else 
                v0.push(i);
        }
        for (int i = 1; i <= n; i++)
        {
            int a, b;
            cin >> a >> b;
            if ((a == 1 || b == 1) && v0.size())
            {
                cout << v0.front() << " 1" << endl;
                v0.pop();
            }
            else if ((a == 2 || b == 2) && v1.size())
            {
                cout << v1.front() << " 2" << endl;
                v1.pop();
            }
            else
            {
                if (v0.size())
                {
                    cout << v0.front() << " 3" << endl;
                    v0.pop();
                }
                else
                {
                    cout << v1.front() << " 3" << endl;
                    v1.pop();
                }
            }
        }
    }
    
}

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}